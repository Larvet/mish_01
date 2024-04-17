/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 17:12:47 by locharve          #+#    #+#             */
/*   Updated: 2024/04/17 18:34:54 by locharve         ###   ########.fr       */
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

void	print_files(t_file *lst)
{
	if (lst)
	{
		printf("%s\n", lst->line);
		free(lst->line); ////////
		print_files(lst->next);
		free(lst); //////////////
	}
}

void	print_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		printf("%s\n", split[i]);
		free(split[i]); /////////
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_mish	mish;
	t_error	*head;

	ft_bzero(&mish, sizeof(mish));
	if (argc == 2)
	{
		mish.line = argv[1];
		printf("check_unhandled : %d\nsyntax_error : %d\nopen_quotes : %d\n\n",
				mish_check_unhandled(&mish),
				mish_check_syntax_error(&mish),
				mish_check_open_quotes(&mish));
		head = mish.error;
		while (mish.error)
		{
			printf("error : %d\n", mish.error->type);
			if (mish.error->data)
				printf("\tdata : %s\n", mish.error->data);
/*			tmp = mish.error;
			mish.error = mish.error->next;
			if (tmp->data)
				free(tmp->data);
			free(tmp);
*/			mish.error = mish.error->next;
		}
		mish.error = head;
		if (mish_separate_processes(&mish))
		{
			print_process_lines(mish.p, mish.nb);
			if (!mish_fill_processes(&mish)) ///////////
			{
				printf("----------INFILES\n");
				print_files(mish.p->infiles);
				printf("----------OUTFILES\n");
				print_files(mish.p->outfiles);
				printf("----------AV\n");
				print_split(mish.p->av);
			}
		}
		t_error_lst_free(&mish.error);
	}
	return (0);
}
