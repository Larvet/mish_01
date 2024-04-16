/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:37:45 by locharve          #+#    #+#             */
/*   Updated: 2024/04/15 17:43:38 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mish.h"
#include "clean_quotes.h"

int	is_alphanum_underscore(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	else
		return (0);
}

size_t	ft_strlen_while(char *str, int *f(char))
{
	int	i;

	i = 0;
	while (str[i] && f(str[i]))
		i++;
	return (i);
}

char	*get_var_value(t_mish *mish, char *var)
{
	char	*sub;

	sub = getenv(&var[1]); ////// mish_env_get(mish, &var[1])
	if (sub)
		sub = ft_strdup(sub);
	else
		sub = ft_calloc(1, sizeof(char));
	if (!sub)
		mish_t_error_add(mish, err_malloc, errno, "get_var_value");
	return (sub);
}

char	*copy_substituting(t_mish *mish, char *src, char *var, char *sub)
{
	char	*dst;
	char	*tmp;
	int		i;

	dst = ft_memmove(dst, &src[1], ft_strlen(src) - 2);
	dst = ft_calloc(ft_strlen(src) - ft_strlen(var) + len_sub - 2 + 1,
			sizeof(char));
	if (dst)
	{
		dst = ft_memmove(dst, &src[1], ft_strlen(src) - 2);
		i = 0;
		while (dst[i] && ft_strncmp(var, &dst[i], ft_strlen(var)))
			i++;
		tmp = ft_strndup(&dst[i + ft_strlen(var)],
					ft_strlen(&dst[i + ft_strlen(var)]));
		if (tmp)
		{
			ft_strcpy(&dst[i], sub);
			ft_strcpy(&dst[i + ft_strlen(sub)], tmp);
			free(tmp);
		}
		else
			mish_t_error_add(mish, err_malloc, errno, "copy_substituting");
	}
	else
		mish_t_error_add(mish, err_malloc, errno, "copy_substituting");
	return (dst);
}

char	*substitute_exit_status(t_mish *mish, char *src, char *var)
{
	char	*sub;
	char	*dst;

	sub = ft_itoa(mish->exit_stat);
	if (sub)
	{
		var = ft_strndup(var, 2);
		if (var)
		{
			dst = copy_substituting(mish, src, var, sub);
			free(var);
		}
		else
			mish_t_error_add(mish, err_malloc,
					errno, "substitute_exit_status");
		free(sub);
	}
	else
		mish_t_error_add(mish, err_malloc, errno, "substitute_exit_status");
	return (dst);
}

char	*substitute_digits(t_mish *mish, char *src, char *var)
{
	char	*sub;
	char	*dst;

	if (var[1] == '0')
		sub = ft_strdup("minishell");
	else
		sub = ft_calloc(1, sizeof(char));
	if (sub)
	{
		var = ft_strndup(var, 2);
		if (var)
		{
			dst = copy_substituting(mish, src, var, sub);
			free(var);
		}
		else
			mish_t_error_add(mish, err_malloc, errno, "substitute_digits");
		free(sub);
	}
	else
		mish_t_error_add(mish, err_mallo, errno, "substitute_digits");
	return (dst);
}

char	*substitute_var(t_mish *mish, char *src, char *var)
{
	char	*dst;
	char	*sub;
	size_t	len_dst;

	if (ft_isdigit(var[1]))
		dst = substitute_digits(mish, src, var);
	else if (ft_isalpha(var[1]) || var[1] == '_')
	{
		sub = get_var_value(mish, src, var);
		if (sub)
		{
			var = ft_strndup(var, ft_strlen_while(var, is_alphanum_underscore));
			if (var)
			{
				dst = copy_substituting(mish, src, var, sub);
				free(var);
			}
			else
				mish_t_error_add(mish, err_malloc, errno, "substitute_var");
			free(sub);
		}
		else
			mish_t_error_add(mish, err_malloc, errno, "substitute_var");
	}
	return (dst);
}

char	*clean_quotes(t_mish *mish, char *src, char q)
{
	char	*dst;
	char	*var;

	if (q == '\"')
	{
		var = ft_strchr(src, '$');
		if (var)
		{
			if (var[1] == '?')
				dst = substitute_exit_status(mish, src, var);
			else if (is_alphanum_underscore(var[1]))
				dst = substitute_var(mish, src, var);
			else
				dst = ft_strndup(&src[1], ft_strlen(src) - 2);
		}
		else
			dst = ft_strndup(&src[1], ft_strlen(src) - 2);
	}
	else if (q == '\'')
		dst = ft_strndup(&src[1], ft_strlen(src) - 2);
	else
		dst = NULL;
	return (dst);
}
