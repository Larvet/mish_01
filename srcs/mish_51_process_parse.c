/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_51_process_parse.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:11:37 by bchene            #+#    #+#             */
/*   Updated: 2024/04/10 15:40:49 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

/*
static char	*ppxp_access_cmd(t_ppx_process *p)
{
	int		i;
	char	*str;
	char	**path;

	path = (p->ppx)->pathlist;
	i = 0;
	while (path && path[i])
	{
		str = ft_strjoin(path[i], (p->av)[0]);
		if (access(str, X_OK) == 0)
			return (str);
		free(str);
		i++;
	}
	str = ft_strdup((p->av)[0]);
	write(2, "Command not found: ", 20);
	write(2, (p->av)[0], ft_strlen((p->av)[0]));
	write(2, "\n", 2);
	return (str);
}
*/



/*
static int	ppx_parse_process(t_ppx *ppx, int num, char *av)
{
	t_ppx_process	*p;

	p = (ppx->p) + num;
	p->ppx = ppx;
	p->index = num;
	p->ac = ft_getnbsplit(av, ' ');
	p->av = NULL;
	if (p->ac == 0)
	{
		write(2, "Error : Empty argument\n", 24);
		ppx_free(ppx);
		exit(EXIT_FAILURE);
	}
	p->av = ft_split(av, ' ');
	if (p->av == NULL)
		ppx_exit_error(ppx, "ft_split error", errno);
	p->cmd = ppxp_access_cmd(p);
	return (0);
}

int	ppx_parse_av(t_ppx *ppx, int ac, char **av)
{
	int	i;

	ppx->nb = ac - 3;
	//ppx->fd_outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ppx->fd_outfile = open(av[ac - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (ppx->fd_outfile == -1)
		ppx_exit_error(ppx, "open error", errno);
	ppx->fd_infile = open(av[1], O_RDONLY);
	if (ppx->fd_infile == -1)
	{
		perror("");
		ppx->fd_infile = dup(ppx->fd_outfile);
	}
	ppx->p = ft_calloc(ppx->nb, sizeof(t_ppx_process));
	if (ppx->p == NULL)
		ppx_exit_error(ppx, "ft_calloc error", errno);
	i = -1;
	while (++i < ppx->nb)
		ppx_parse_process(ppx, i, av[i + 2]);
	ppx_mallocfds(ppx);
	ppx->pid = ft_calloc(ppx->nb, sizeof(int));
	if (ppx->pid == NULL)
		ppx_exit_error(ppx, "ft_calloc error", errno);
	return (0);
}

*/
