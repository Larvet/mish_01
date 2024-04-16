/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_check_syntax_error.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:39:36 by locharve          #+#    #+#             */
/*   Updated: 2024/04/16 19:29:52 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int	is_special_token(char *line, int i)
{
	char	r;

	if (is_in_str("<>", line[i]))
	{
		r = line[i];
		if (line[i + 1] == r)
			return (2);
		else
			return (1);
	}
	else if (line[i] == '|')
		return (1);
	else
		return (0);
}

static char	*next_char_addr(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_in_str(WHITESPACES, str[i]))
		i++;
	if (str[i])
		return (&str[i]);
	else
		return (NULL);
}

int	mish_check_syntax_error(t_mish *mish)
{
	char	*err;
	int		i;
	int		tmp[2];
	int		result;

	i = 0;
	while (mish->line && mish->line[i])
	{
		tmp[0] = is_special_token(mish->line, i);
		if (tmp[0])
		{
			i += tmp[0];
			tmp[1] = is_special_token(mish->line, i);
			if (tmp[1])
			{
				err = ft_strndup(&mish->line[i], tmp[1]); // malloc
				result = mish_t_error_add(mish, err_token_unexpected,
						errno, err);
				free(err);
				return (result);
			}
			else if (!next_char_addr(&mish->line[i]))
			{
				err = ft_strndup("newline",7); // malloc
				result = mish_t_error_add(mish, err_token_unexpected,
						errno, err);
				free(err);
				return (result);
			}
			tmp[0] = 0;
		}
		else
			i++;
	}
	return (0);
}
