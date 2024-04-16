/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_10_prompt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 14:35:09 by bchene            #+#    #+#             */
/*   Updated: 2024/04/10 16:23:39 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"
/*
static void	mish_setprompt(t_mish *mish)
{
	mish->prompt = ft_strjoin(mish->prompt, "\033[0;31m:>user");
}
*/
static void	mish_setprompt(t_mish *mish)
{
	char	*session_m;

	session_m = getenv("SESSION_MANAGER");
	session_m = ft_strchr(session_m, '/');
	session_m = ft_strndup(session_m + 1, ft_strchr(session_m, '.') - (session_m + 1));
	if (!session_m)
		return ;
	mish->prompt = ft_strjoin_va("", "\001\e[1;36m\002\001\e[40m\002",
			getenv("LOGNAME"), "\001\e[0;35m\002\001\e[40m\002", 
			" @", session_m, " ", "\001\e[0;34m\002\001\e[40m\002",
			ft_strnrchr(getenv("PWD"), 2, '/'), "/", "\001\e[0m\002 $>", NULL);
	free(session_m);
	return ;
}

static void	mish_first_prompt(t_mish *mish)
{
	mish_setprompt(mish);
	mish->prompt = ft_strjoin("\001\e[0;31m\002:::::::::::::::::::::>MINISHELL \n\
\001\e[0;32m\002::::::::::::::::::>MINISHELL \n\
\001\e[0;33m\002:::::::::::::::>MINISHELL \n\
\001\e[0;34m\002::::::::::::>MINISHELL \n\
\001\e[0;35m\002:::::::::>MINISHELL \n\
\001\e[0;36m\002::::::>MINISHELL \n", \
	mish->prompt);
	mish->line = readline(mish->prompt);
}

void	mish_prompt(t_mish *mish)
{
	char	**split;

	mish_first_prompt(mish);
	mish->line = readline(mish->prompt);
	while (mish->line)
	{
		add_history(mish->line);
		// parsing tokkening process
		//printf("%s", mish->prompt); //
		//
/*		separate_processes(mish);
		if (mish->error.type)
			print_error(mish);
*/		
		split = ft_split_mish(mish, WHITESPACES);
		ft_print_split(split);
		//
		free(mish->prompt);
		free(mish->line);
		free_strtab(split);
		mish_setprompt(mish);
		mish->line = readline(mish->prompt);
	}
	free(mish->prompt);
	rl_clear_history();
}