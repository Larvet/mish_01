/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:14:07 by locharve          #+#    #+#             */
/*   Updated: 2024/04/23 16:24:37 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int	mish_parsing(t_mish *mish)
{
	int	v;

	v = is_there_a_var(mish->line);
	if (v)
		mish_var_dup(mish, &mish->line, &mish->line[v]); // malloc
	if (mish->line && !mish_check_syntax_error(mish)
			&& !mish_check_unhandled(mish)
			&& !mish_check_open_quotes(mish)
			&& mish_separate_processes(mish)
			&& !mish_fill_processes(mish))
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv)
{
	t_mish	mish;

	ft_bzero(&mish, sizeof(mish));
	if (argc == 2)
	{
		mish.line = ft_strdup(argv[1]);
		if (mish.line && mish_parsing(&mish))
		{
			mish_print_processes_free(&mish); ///
			t_error_lst_free(&mish.error);
			free(mish.line);
		}
	}
	return (0);
}
