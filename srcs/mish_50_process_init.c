/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_50_process_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 13:49:39 by bchene            #+#    #+#             */
/*   Updated: 2024/04/10 16:24:48 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_process	*t_process_new(t_mish *mish, int index, char *line)
{
	t_process	*process;

	process = malloc(sizeof(t_process));
	if (process == NULL)
		return (NULL);
	process->mish = mish;
	process->index = index;
	process->line = line;
	process->ac = 0;
	process->av = NULL;
	process->cmd = NULL;
	process->infiles = NULL;
	process->outfiles = NULL;
	process->next = NULL;
	return (process);
}

t_process	*t_process_addnext(t_mish *mish, int index, char *line)
{
	t_process	*process;
	process = mish->p;
	if (process == NULL)
	{
		mish->p = t_process_new(mish, index, line);
		return (mish->p);
	}
	while (process->next)
		process = process->next;
	process->next = t_process_new(mish, index, line);
	return (process->next);
}

void	t_process_free(t_process *process)
{
	int	i;

	if (process == NULL)
		return ;
	ft_freesplit(process->av);
	if (process->cmd)
		free(process->cmd);
	i = -1;
	if (process->infiles)
	{
		if ((process->infiles) + (++i))
			t_file_free((process->infiles) + i);
		free(process->infiles);
	}
	i = -1;
	if (process->outfiles)
	{
		if ((process->outfiles) + (++i))
			t_file_free((process->outfiles) + i);
		free(process->outfiles);
	}
}

void	t_process_delall(t_mish *mish)
{
	t_process	*process;
	t_process	*next;

	if (mish && mish->p)
	{
		process = mish->p;
		while (process->next)
		{
			next = process->next;
			t_process_free(process);
			process = next;
		}
		t_process_free(process);
	}
}

void	t_process_printf(t_process *p)
{
	printf("|||| T_PROCESS\n");
	printf("index = %d\n", p->index);
	printf("line = %s\n", p->line);
	printf("ac = %d\n", p->ac);
	printf("av = ");
	ft_printf_strtab(p->av, p->ac, "\\-\\");
	printf("\n");
	printf("cmd = %s\n", p->cmd);
	printf("|||| T_PROCESS\n");
}