/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 11:56:55 by locharve          #+#    #+#             */
/*   Updated: 2024/04/08 11:56:56 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int is_unexpected_token(t_mish *mish, char *set, char c)
{
    int i;

    if (c)
    {
        i = 0;
        while (set[i] && c != set[i])
			i++;
		if (set[i])
		{
			mish->error.type = __unexpected_token;
			mish->error.data = ft_calloc(2, sizeof(char));
			if (mish->error.data)
				mish->error.data[0] = c;
		}
	}
	else
	{
		mish->error.type = __unexpected_token;
		mish->error.data = ft_strdup("newline");
	}
	if (mish->error.type)
		return (1);
	else
		return (0);
}

int	is_unexpected_redir(t_mish *mish, char *nbr_addr) ///////////// nooooo
{
	long long	nbr;
	int			j;

	if (nbr_addr)
	{
		nbr = ft_atoll(nbr_addr);
		j = 0;
		while (is_digit(nbr_addr[j]))
			j++;
		if (is_in_str("<>", nbr_addr[j]) && (nbr < 0 || nbr > 2147483647))
		{
			mish->error.type = __unexpected_token;
			mish->error.data = ft_itoa(nbr);
			return (1);
		}
	}
	return (0);
/*	j = 0;
	if (mish->line[i + j])
	{
		if (is_digit(mish->line[i + j]))
			nbr = ft_atoll(&mish->line[i + j]);
		while (is_digit(mish->line[i + j]))
			j++;
		if (mish->line[i + j] && is_in_str("<>", mish->line[i + j])
				&& (nbr < 0 || nbr > 2147483647))
		{
			mish->error.type = __unexpected_token;
			mish->error.data = ft_itoa(nbr);	//////
			printf("data = %s\n", mish->error.data); //////
		}
	}
	if (mish->error.type)
		return (1);
	else
		return (0);	*/
}

int	is_bad_fd(t_mish *mish, int i)
{
	long long	nbr;

	nbr = ft_atoll(&mish->line[i]);
	if (nbr >= 1024)
	{
		mish->error.type = __bad_fd;
		mish->error.data = ft_itoa(nbr);
		return (1);
	}
	else
		return (0);
}
