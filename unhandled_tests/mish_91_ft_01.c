/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_91_ft_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 14:20:05 by locharve          #+#    #+#             */
/*   Updated: 2024/04/18 15:05:27 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	is_alphanum_underscore(char c)
{
	if (ft_isalpha(c) || ft_isdigit(c) || c == '_')
		return (1);
	else
		return (0);
}

size_t	ft_strlen_while(char *str, int f(char))
{
	int	i;

	i = 0;
	while (str[i] && f(str[i]))
		i++;
	return (i);
}
