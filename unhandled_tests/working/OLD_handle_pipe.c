/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OLD_handle_pipe.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:05:08 by locharve          #+#    #+#             */
/*   Updated: 2024/04/08 13:05:09 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int handle_pipe(t_mish *mish, int *i)
{
	int j;

	j = 1;
	while (mish->line[*i + j] && is_in_str(WHITESPACES, mish->line[*i + j]))
		j++;
	if (mish->line[*i + j] == '|')
	{
		mish->error.type = __unexpected_token;
		mish->error.data = ft_calloc(2, sizeof(char));
		if (mish->error.data)
			mish->error.data[0] = '|';
		return (j);
	}
	else
		return (1);
}
