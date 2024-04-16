/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:12:47 by locharve          #+#    #+#             */
/*   Updated: 2024/04/16 19:29:16 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	main(int argc, char **argv)
{
	t_mish	mish;
	t_error	*tmp;

	ft_bzero(&mish, sizeof(mish));
	if (argc == 2)
	{
		mish.line = argv[1];
		printf("check_unhandled : %d\nsyntax_error : %d\n\n",
				check_unhandled(&mish), mish_check_syntax_error(&mish));
		while (mish.error)
		{
			printf("error : %d\n", mish.error->type);
			if (mish.error->data)
				printf("\tdata : %s\n", mish.error->data);
			tmp = mish.error;
			mish.error = mish.error->next;
			if (tmp->data)
				free(tmp->data);
			free(tmp);
		}
	}
	return (0);
}
