/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_unhandled.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:13:05 by locharve          #+#    #+#             */
/*   Updated: 2024/04/16 19:27:29 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

static int	not_between_quotes(t_mish *mish, char *line, int i)
{
	int		j;
	int		q;

	j = i;
	while (j >= 0 && (line[j] != '\'' && line[j] != '\"'))
		j--;
	q = line[j];
	if (q)
	{
		while (line[i] && line[i] != q)
			i++;
		if (!line[i] && q == '\'')
			return (mish_t_error_add(mish, err_quote_open,
					errno, "between_quotes - open quotes"));
		else if (!line[i] && q == '\"')
			return(mish_t_error_add(mish, err_dquote_open,
					errno, "between_quotes - open double quotes"));
		else
			return (0);
	}
	else
		return (1);
		//return (mish_t_error_add(mish, err_unhandled,
		//		errno, "between_quotes"));
}

int	check_unhandled(t_mish *mish)
{
	char	*err;
	int		i;

	i = 0;
	while (mish->line && mish->line[i])
	{
		if (is_in_str("\\;&()", mish->line[i])
				&& not_between_quotes(mish, mish->line, i))
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
						"check_unhandled"));
		}
		i++;
	}
	return (0);
}
/*
int	main(int argc, char **argv)
{
	t_mish	mish;
	t_error	*tmp;

	ft_bzero(&mish, sizeof(mish));
	if (argc == 2)
	{
		mish.line = argv[1];
		printf("\tcheck_unhandled : %d\n", check_unhandled(&mish));
		while (mish.error)
		{
			printf("error : %d\n", mish.error->type);
			if (mish.error->data)
				printf("\tdata : %s\n", mish.error->data);
			tmp = mish.error;
			mish.error = mish.error->next;
			if (tmp->data)
				free(tmp->data);
			free(tmp);
		}
	}
	return (0);
}
*/