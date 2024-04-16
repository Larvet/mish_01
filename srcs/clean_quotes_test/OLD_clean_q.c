/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_clean_q.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:13:21 by locharve          #+#    #+#             */
/*   Updated: 2024/04/12 13:34:59 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "mish.h"
#include "clean_quotes.h"

size_t	ft_strlen_until(char *str, char *stop)
{
	size_t	i;

	i = 0;
	while (str[i] && !is_in_str(stop, str[i]))
		i++;
	return (i);
}
// $?
char	*get_var_value(char *str, char **name, size_t *len_name)
{
	char	*val;

	*name = ft_strchr(str, '$');
	printf("name 0 = %s\n", *name); //////
	val = NULL;
	if (*name && (*name)[1] && (ft_isalpha((*name)[1]) || (*name)[1] == '_'))
	{
		*len_name = ft_strlen_until(&((*name)[1]), WHITESPACES_QUOTES);
		*name = ft_strndup(&((*name)[1]), *len_name);
		if (*name)
		{
			val = getenv(*name);
			printf("val = |%s|\n", val); /////
			if (!val)
				val = ft_calloc(1, sizeof(char));
			//free(name);
		}
	}
	return (val);
}

char	*substitute_var(char *src, char *name, char *var, size_t dst_len)
{
	char	*dst;
	char	*tmp;
	//char	q;
	size_t	i;
	size_t	j;

	dst = ft_calloc(dst_len + 1, sizeof(char));
	if (dst)
	{
		dst = ft_memmove(dst, &src[1], ft_strlen(src) - 2);
		i = 0;
		while (dst[i] && ft_strncmp(name, &dst[i], ft_strlen(name)))
			i++;
		if (dst[i])
		{
			tmp = ft_strndup(&dst[i + ft_strlen(name)],
					ft_strlen(&dst[i + ft_strlen(name)]));
			printf("tmp = |%s|\n", tmp);
			j = 0;
			while (var[j])
			{
				dst[i + j] = var[j];
				j++;
			}
			i += j;
			j = 0;
			while (tmp[j])
			{
				dst[i + j] = tmp[j];
				j++;
			}
			free(tmp);
		}
	}
	return (dst);
}

char	*clean_quotes(char *src, char q)
{
	char	*name;
	char	*val;
	char	*dst;
	size_t	len_name;
	size_t	len_val;
	size_t	src_len;
	size_t	dst_len;

	name = NULL;
	src_len = ft_strlen(src);
	if (q == '\"') // substitution
	{
		val = get_var_value(src, &name, &len_name); // empty string if var doesn't exist // NULL if no $
		printf("name = %s\n", name); //////
		if (val)
		{
			len_val = ft_strlen(val);
			dst_len = src_len - len_name + len_val - 2;
			dst = substitute_var(src, name, val, dst_len); // malloc
		}
		else
			dst = ft_strndup(&src[1], src_len - 2);
		if (name)
			free(name);
	}
	else if (q == '\'')
		dst = ft_strndup(&src[1], src_len - 2);
	else
		dst = NULL;
	return (dst);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	q;

	str = NULL;
	if (argc == 2)
	{
		printf("avant:\t|%s|\n", argv[1]);
		q = argv[1][0];
		str = clean_quotes(argv[1], q);
		if (str)
		{
			printf("après:\t|%s|\n", str);
			free(str);
		}
	}
	return (0);
}
