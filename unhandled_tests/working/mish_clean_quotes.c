/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_clean_quotes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 15:54:47 by locharve          #+#    #+#             */
/*   Updated: 2024/04/18 16:48:25 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

char	*substitute_hub(t_mish *mish, char *src, char *var)
{
	char	*dst;

	if (var[0] == '?')
		dst = substitute_exit_status(mish, src, var);
	else if (ft_isdigit(var[0]))
		dst = substitute_digits(mish, src, var);
	else if (ft_isalpha(var[0]) || var[0] == '_')
		dst = substitute_var(mish, src, var);
	else
		dst = ft_strndup(&src[1], ft_strlen(src) - 2);
	return (dst);
}

char	*clean_quotes(t_mish *mish, char *src, char q)
{
	char	*dst;
	char	*var;

	dst = NULL;
	var = src;
	if (q == '\"') // substitution
	{
		var = ft_strchr(var, '$');
		if (var) // while ?
		{
			var = ft_strndup(&var[1],
					ft_strlen_while(&var[1], is_alphanum_underscore));
			if (var)
			{
				dst = substitute_hub(mish, src, var);
				free(var);
			}
		}
		else
			dst = ft_strndup(&src[1], ft_strlen(src) - 2);
	}
	else if (q == '\'')
		dst = ft_strndup(&src[1], ft_strlen(src) - 2);
	free(src); ////
	return (dst);
}

void	mish_clean_all_quotes(t_mish *mish, char **p_lines)
{
	int	i;

	i = 0;
	while (p_lines && p_lines[i])
	{
		if (p_lines[i][0] == '\'' || p_lines[i][0] == '\"')
			p_lines[i] = clean_quotes(mish, p_lines[i], p_lines[i][0]); // malloc
		i++;
	}
	return ;
}
