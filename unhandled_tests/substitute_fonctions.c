/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substitute_fonctions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 16:05:56 by locharve          #+#    #+#             */
/*   Updated: 2024/04/18 17:31:01 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

char	*get_var_value(t_mish *mish, char *var)
{
	char	*sub;

	sub = getenv(var); ///// mish_get_env
	if (sub)
	{
		sub = ft_strdup(sub); // malloc
		if (!sub)
			mish_t_error_add(mish, err_malloc, errno, "get_var_value");
	}
	else
		sub = ft_calloc(1, sizeof(char));
	return (sub);
}

char	*dup_substituting(char *src, char *var, char *sub)
{
	char	*dst;
	char	*var_addr;
	char	*tmp;
	size_t	len_src;
	size_t	len_var;
	size_t	len;

	len_src = ft_strlen(src);
	len_var = ft_strlen(var);
	dst = ft_calloc(len_src - (len_var + 1)
			+ ft_strlen(sub) + 1, sizeof(char));
	var_addr = src;
	if (dst)
	{
		//dst = ft_memmove(dst, &src[1], len_src - 2);
		while (ft_strncmp(&var_addr[1], var, len_var))
			var_addr = ft_strchr(src, '$');
		tmp = ft_strdup(&var_addr[len_var + 1]);
		if (tmp)
		{
			ft_strncpy(dst, src, var_addr - src); ///
			len = ft_strlen(dst);
			ft_strcpy(&dst[len], sub);
			len = ft_strlen(dst);
			ft_strcpy(&dst[len], tmp);
			free(tmp);
			tmp = ft_strndup(&dst[1], ft_strlen(dst) - 2); // malloc
			free(dst);
			if (tmp)
				dst = tmp;
		}
	}
	return (dst);
}

char	*substitute_exit_status(t_mish *mish, char *src, char *var)
{
	char	*dst;
	char	*sub;

	sub = ft_itoa(mish->exit_stat);
	if (sub)
	{
		dst = dup_substituting(src, var, sub); // malloc
		if (!dst)
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
	char	*dst;
	char	*sub;

	if (var[0] == '0')
		sub = ft_strdup("minishell");
	else
		sub = ft_calloc(1, sizeof(char));
	if (sub)
	{
		dst = dup_substituting(src, var, sub);
		if (!dst)
			mish_t_error_add(mish, err_malloc, errno, "substitute_digits");
		free(sub);
	}
	else
		mish_t_error_add(mish, err_malloc, errno, "substitute_digits");
	return (dst);
}

char	*substitute_var(t_mish *mish, char *src, char *var)
{
	char	*dst;
	char	*sub;

	dst = NULL;
	sub = get_var_value(mish, var);
	if (sub)
	{
		dst = dup_substituting(src, var, sub);
		if (!dst)
			mish_t_error_add(mish, err_malloc, errno, "dub_substituting");
		free(sub);
	}
	else
		mish_t_error_add(mish, err_malloc, errno, "substitute_var");
	return (dst);
}
