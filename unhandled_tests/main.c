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

void	print_process_lines(t_process *p, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (p[i].line)
		{
			printf("p->line:\t%s\n", p[i].line);
			free(p[i].line);
		}
		else
			printf("error\n");
		i++;
	}
	free(p);
	return ;
}

int	main(int argc, char **argv)
{
	t_mish	mish;
	t_error	*tmp;

	ft_bzero(&mish, sizeof(mish));
	if (argc == 2)
	{
		mish.line = argv[1];
		printf("check_unhandled : %d\nsyntax_error : %d\n\n",
				mish_check_unhandled(&mish),
				mish_check_syntax_error(&mish));
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
		if (mish_separate_processes(&mish))
			print_process_lines(mish.p, mish.nb);
	}
	return (0);
}
