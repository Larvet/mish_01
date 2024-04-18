/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_clean_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 13:37:45 by locharve          #+#    #+#             */
/*   Updated: 2024/04/18 15:43:54 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"
//#include "clean_quotes.h"

char	*get_var_value(t_mish *mish, char *var)
{
	char	*sub;

	sub = NULL;
	size_t	len = ft_strlen_while(&var[1], is_alphanum_underscore);
	printf("len = %ld\n", len);
	var = ft_strndup(&var[1], len);
	if (var)
	{
		printf("var = %s\n", var); ////
		sub = getenv(var); ////// mish_env_get(mish, &var[1])
		printf("sub = %s\n", sub); ////
		if (sub)
			sub = ft_strdup(sub);
		else
			sub = ft_calloc(1, sizeof(char));
		if (!sub)
			mish_t_error_add(mish, err_malloc, errno, "get_var_value");
		free(var);
	}
	return (sub);
}

char	*copy_substituting(t_mish *mish, char *src, char *var, char *sub)
{
	char	*dst;
	char	*tmp;
	int		i;

	dst = ft_calloc(ft_strlen(src) - ft_strlen(var)
			+ ft_strlen(sub) - 2 + 1, sizeof(char));
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
		mish_t_error_add(mish, err_malloc, errno, "substitute_digits");
	return (dst);
}

char	*substitute_var(t_mish *mish, char *src, char *var)
{
	char	*dst;
	char	*sub;

	dst = NULL;
	if (ft_isdigit(var[1]))
		dst = substitute_digits(mish, src, var);
	else if (ft_isalpha(var[1]) || var[1] == '_')
	{
		sub = get_var_value(mish, var);
		//printf("sub = %s\n", sub); /////
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
	printf("dst = %s\n", dst); ////
	return (dst);
}

void	mish_clean_all_quotes(t_mish *mish, char **p_lines)
{
	int	i;

	i = 0;
	while (p_lines && p_lines[i])
	{
		if (is_in_str("\'\"", p_lines[i][0]))
			p_lines[i] = clean_quotes(mish, p_lines[i], p_lines[i][0]);
		i++;
	}
}
