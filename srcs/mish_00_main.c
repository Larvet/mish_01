/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_00_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:14:32 by bchene            #+#    #+#             */
/*   Updated: 2024/04/10 16:13:24 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

const static int	SIGMISH;

int	main(void)
{
	t_mish	mish;

	ft_bzero(&mish, sizeof(mish));
	mish_prompt(&mish);
	return (0);
}
