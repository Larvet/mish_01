/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_91_ft_00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:29:31 by bchene            #+#    #+#             */
/*   Updated: 2024/04/10 15:00:17 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

/*  */
char	*ft_strnrchr(char *str, int n, char c)
{
	size_t	i;

	i = ft_strlen(str);
	while (i > 0 && n > 0)
	{
		i--;
		if (str[i] == c)
			n--;
	}
	return (&str[i]);
}

/* free str and return empty char* "" */
char	*ft_strempty(char *str)
{
	if (str)
		free(str);
	str = malloc(sizeof(char));
	if (str == NULL)
		return (NULL);
	*str = 0;
	return (str);
}

/* printf split parts */
void	ft_print_split(char **pathlist)
{
	int	j;

	j = -1;
	while (pathlist && pathlist[++j])
		ft_printf("%s\n", pathlist[j]);
}

void	ft_printf_strtab(char **str, int size, const char *sep)
{
	int	i;

	i = 0;
	while(i < size)
	{
		if (i != 0)
			write(1, sep, ft_strlen(sep));
		if (str[i])
			write(1, str[i], ft_strlen(str[i]));
		i++;
	}
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = 0;
		i++;
	}
	return ;
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ptr;

	if ((nmemb > 65535 && size > 65535) || nmemb * size > 2147483647)
		return (NULL);
	ptr = (unsigned char *)malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return ((void *)ptr);
}