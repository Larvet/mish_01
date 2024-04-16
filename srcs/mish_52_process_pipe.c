/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_52_process_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:17:07 by bchene            #+#    #+#             */
/*   Updated: 2024/04/09 14:32:02 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

/*
int	ppx_mallocfds(t_ppx *ppx)
{
	int	i;

	ppx->fds = malloc(ppx->nb * sizeof(int *));
	if (ppx->fds == NULL)
		ppx_exit_error(ppx, "malloc error", errno);
	i = -1;
	while (++i < ppx->nb)
	{
		(ppx->fds)[i] = malloc(2 * sizeof(int));
		if ((ppx->fds)[i] == NULL)
			ppx_exit_error(ppx, "malloc error", errno);
		(ppx->fds)[i][0] = -1;
		(ppx->fds)[i][1] = -1;
	}
	return (0);
}

void	ppx_closefd(int *fd)
{
	if (*fd > 2)
	{
		close(*fd);
		*fd = -1;
	}
}

void	ppx_closeallfds(t_ppx *ppx)
{
	int	i;

	i = -1;
	while (++i < ppx->nb)
	{
		ppx_closefd(&(ppx->fds[i][0]));
		ppx_closefd(&(ppx->fds[i][1]));
	}
	ppx_closefd(&(ppx->fd_infile));
	ppx_closefd(&(ppx->fd_outfile));
}

int	ppx_createfds(t_ppx *ppx)
{
	int	i;

	i = -1;
	while (++i < ppx->nb)
		if (pipe((ppx->fds)[i]) == -1)
			ppx_exit_error(ppx, "pipe error", errno);
	return (0);
}

int	ppx_child_pipe(t_ppx *ppx, int n)
{
	int	i;

	if (n == 0)
		if (dup2(ppx->fd_infile, STDIN_FILENO) == -1)
			ppx_exit_error(ppx, "dup2 error", errno);
	i = -1;
	while (++i < ppx->nb)
	{
		if (i == n && i > 0)
			if (dup2((ppx->fds)[i][0], STDIN_FILENO) == -1)
				ppx_exit_error(ppx, "dup2 error", errno);
		if (i == n && i < (ppx->nb - 1))
			if (dup2((ppx->fds)[(i + 1)][1], STDOUT_FILENO) == -1)
				ppx_exit_error(ppx, "dup2 error", errno);
	}
	if (n == ppx->nb - 1)
		if (dup2(ppx->fd_outfile, STDOUT_FILENO) == -1)
			ppx_exit_error(ppx, "dup2 error", errno);
	ppx_closeallfds(ppx);
	return (0);
}
*/
