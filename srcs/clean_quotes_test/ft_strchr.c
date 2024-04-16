/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:26:49 by bchene            #+#    #+#             */
/*   Updated: 2024/04/11 17:23:43 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "clean_quotes.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *) s;
	while (*p)
	{
		if (*p == (char)c)
			return (p);
		p++;
	}
	if ((char)c == 0)
		return (p);
	return (NULL);
}

char	*ft_strswitnchr(char *s, char src, char dest)
{
	char	*s1;

	s1 = ft_strchr(s, src);
	if (s1)
		*s1 = dest;
	return (s);
}
