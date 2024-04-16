/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:06:45 by locharve          #+#    #+#             */
/*   Updated: 2024/04/15 15:16:33 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_test.h"

int	main(int argc, char **argv, char **envp)
{
	t_mish	mish;

	mish_env_init(&mish, envp);
	mish_print_env(&mish);
	return (0);
}
