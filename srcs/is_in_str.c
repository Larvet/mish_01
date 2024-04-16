/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_in_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:12:14 by locharve          #+#    #+#             */
/*   Updated: 2024/03/27 16:21:08 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	is_digit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	is_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && c != str[i])
		i++;
	if (!str[i])
		return (0);
	else
		return (1);
}
