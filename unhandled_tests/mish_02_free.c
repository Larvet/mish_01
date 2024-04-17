/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_02_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 17:34:27 by bchene            #+#    #+#             */
/*   Updated: 2024/04/17 17:38:55 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"
/*
void	t_mish_free(t_mish *mish)
{
	if (mish->error->data)
		free(mish->error->data);
	if (mish->prompt)
		free(mish->prompt);
	if (mish->line)
		free(mish->line);
	if (mish->splitline)
		ft_freesplit(mish->splitline);
	if (mish->p)
		t_process_delall(mish);
	if (mish->fds)
		free(mish->fds);
	ft_freesplit(mish->pathlist);
}

void	t_file_free(t_file *tf)
{
	if (tf->fd != -1)
	{
		close(tf->fd);
		tf->fd = -1;
	}
	if (tf->name)
		free(tf->name);
	if (tf->path)
		free(tf->path);
	if (tf->data)
		free(tf->data);
	if (tf->here_doc)
		free(tf->here_doc);
}
*/

void	t_error_free(t_error *err)
{
	if (err)
	{
		if (err->data)
		{
			free(err->data);
		}
		free(err);
	}
}

void	t_error_lst_free(t_error **err)
{
	if (err)
	{
		if (*err)
		{
			if ((*err)->next)
				t_error_lst_free(&(*err)->next);
			t_error_free(*err);
		}
	}
}

void	strtab_free(char **strtab)
{
	int	i;

	i = 0;
	if (strtab)
	{
		while (strtab[i])
		{
			free(strtab[i]);
			i++;
		}
		free(strtab);
	}
	return ;
}
