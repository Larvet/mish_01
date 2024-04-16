/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_53_process_exec.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:28:12 by bchene            #+#    #+#             */
/*   Updated: 2024/04/09 14:24:22 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

/*
static void	ppx_process_child(t_ppx *ppx, t_ppx_process *p)
{
	int	i;

	i = p->index;
	while (--i >= 0)
		waitpid(ppx->pid[i], NULL, 0);
	ppx_child_pipe(ppx, p->index);
	if (execve(p->cmd, p->av, ppx->envp) == -1)
		ppx_exit_error(ppx, "execve error", errno);
	exit (EXIT_FAILURE);
}

int	ppx_process_root(t_ppx *ppx)
{
	int	i;

	i = -1;
	while (++i < ppx->nb)
		if (pipe((ppx->fds)[i]) == -1)
			ppx_exit_error(ppx, "pipe error", errno);
	i = -1;
	while (++i < ppx->nb)
	{
		ppx->pid[i] = fork();
		if (ppx->pid[i] == -1)
			ppx_exit_error(ppx, "fork error", errno);
		if (ppx->pid[i] == 0)
			ppx_process_child(ppx, (ppx->p) + i);
	}
	ppx_closeallfds(ppx);
	i = ppx->nb;
	while (--i >= 0)
		waitpid(ppx->pid[i], NULL, 0);
	return (0);
}
*/
