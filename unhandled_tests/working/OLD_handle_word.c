/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_handle_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:35:22 by locharve          #+#    #+#             */
/*   Updated: 2024/04/17 16:40:53 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	handle_quotes(t_mish *mish, int *i, char q)
{
	int	j;

	j = 1;
	while (mish->line[*i + j] && mish->line[*i + j] != q)
		j++;
	if (!mish->line[*i + j])
	{
		if (q == '\'')
			mish->error.type = __open_quote;
		else if (q == '\"')
			mish->error.type = __open_dquote;
	}
	return (j + 1);
}

int	handle_redirections(t_mish *mish, int *i, char r)
{
	int	j;

	j = 1;
	if (mish->line[*i + j] == r)
		j++;
	while (is_in_str(WHITESPACES, mish->line[*i + j]))
		j++;
	if (!is_unexpected_token(mish, "&<>|", mish->line[*i + j]))
	{
		while(mish->line[*i + j] && !is_in_str(WHITESPACES, mish->line[*i + j])
				&& !is_in_str(SPECIAL_SEP, mish->line[*i + j]))
			j++;
	}
	return (j);
}

int	handle_specials(t_mish *mish, int *i)
{
	char	c;

	c = mish->line[*i];
	if (c == '\'' || c == '\"')
		return (handle_quotes(mish, i, c));
	else if (c == '<' || c == '>')
		return (handle_redirections(mish, i, c));
	else if (c == '|')
		return (handle_pipe(mish, i));
	else
		return (-1);
}

int	handle_word(t_mish *mish, char *sep, int *i)
{
	int	j;

	j = 0;
	if (is_in_str(SPECIAL_SEP, mish->line[*i]))
		j = handle_specials(mish, i);
	else
	{
		while (mish->line[*i + j] && !is_in_str(sep, mish->line[*i + j])
				&& !is_in_str(SPECIAL_SEP, mish->line[*i + j]))
			j++;
	}
	return (j);
}
