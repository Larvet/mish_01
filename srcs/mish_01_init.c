/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_01_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:18:23 by bchene            #+#    #+#             */
/*   Updated: 2024/04/10 16:16:45 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_mish	*t_mish_init(t_mish *mish)
{
	mish->error.type = 0;
	mish->error.data = NULL;
	mish->prompt = NULL;
	mish->line = NULL;
	mish->splitline = NULL;
	mish->nb = 0;
	mish->p = NULL;
	mish->fds = NULL;
	mish->pathlist = NULL;
	return (mish);
}

t_file	*t_file_init()
{
	t_file	*tf;

	tf = malloc(sizeof(t_file));
	if (tf == NULL)
		return (NULL);
	tf->fd = -1;
	tf->name = NULL;
	tf->path = NULL;
	tf->o_method = -1;
	tf->data = NULL;
	tf->here_doc = NULL;
	return (tf);
}

//t_err_type	mish_set_error(t_err_type type, char *data)

static int	mish_parse_path_nullenv(t_mish *mish)
{
	mish->pathlist = malloc(sizeof(char *) * 2);
	if (mish->pathlist == NULL)
	{
		//mish_exit_error(ppx, "malloc error", errno);
		// return(mish_set_error(42,"malloc error"));
		mish->error.type = 42;
		return (mish->error.type);
	}	
	mish->pathlist[0] = malloc(sizeof(char));
	if (mish->pathlist[0] == NULL)
	{
		//ppx_exit_error(ppx, "malloc error", errno);
		mish->error.type = 42;
		return (mish->error.type);
	}	
	mish->pathlist[0] = ft_strempty(mish->pathlist[0]);
	if (mish->pathlist[0] == NULL)
	{
		//ppx_exit_error(ppx, "malloc error", errno);	
		mish->error.type = 42;
		return (mish->error.type);
	}
	mish->pathlist[1] = NULL;
	return (0);	
}

int	mish_parse_path(t_mish *mish)
{
	int		i;
	char	*pathstr;
	char	*tmpstr;

	pathstr = ft_strdup(getenv("PATH"));
	if (pathstr == NULL || ft_strlen(pathstr) == 0)
	{
		mish_parse_path_nullenv(mish);
		return (mish->error.type);
	}
	tmpstr = pathstr;
	pathstr = ft_strjoin(":", tmpstr);
	free(tmpstr);
	mish->pathlist = ft_split(pathstr, ':');
	if (mish->pathlist == NULL)
	{
		mish_parse_path_nullenv(mish);
		return (mish->error.type);
	}
	i = 0;
	while (mish->pathlist[(++i)])
		mish->pathlist[i] = ft_strjointo(mish->pathlist[i], "/");
	mish->pathlist[0] = ft_strempty(mish->pathlist[0]);
	free(pathstr);
	return (0);
}
