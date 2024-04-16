/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 15:25:34 by locharve          #+#    #+#             */
/*   Updated: 2024/04/12 16:51:56 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

static int	not_between_quotes(char *line, int i)
{
	int		j;
	int		q;

	j = i;
	while (j >= 0 && (line[j] != '\'' || line[j] != '\"'))
		j--;
	q = line[j];
	if (q)
	{
		while (line[i] && line[i] != q)
			i++;
		if (!line[i] && q == '\'')
			return (mish_t_error_add(mish, err_quote_open,
					errno, "between_quotes"));
		else if (!line[i] && q == '\"')
			return(mish_t_error_add(mish, err_dquote_open,
					errno, "between_quotes"));
		else
			return (0);
	}
	else
		return (mish_t_error_add(mish, err_unhandled,
				errno, "between_quotes"));
}

int	check_unhandled(t_mish *mish)
{
	char	*err;
	int		i;

	i = 0;
	while (mish->line && mish->line[i])
	{
		if (is_in_str("\\;&()", mish->line[i])
				&& !not_between_quotes(mish->line, i))
		{
			err = ft_calloc(2, sizeof(char));
			if (err)
			{
				err[0] = mish->line[i];
				mish_t_error_add(mish, err_unhandled, errno, err);
				free(err);
				return (err_unhandled);
			}
			else
				return (mish_t_error_add(mish, err_malloc, errno,
						"check_unhandled");)
		}
		i++;
	}
	return (0);
}