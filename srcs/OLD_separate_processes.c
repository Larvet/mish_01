/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separate_processes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:01:50 by locharve          #+#    #+#             */
/*   Updated: 2024/04/10 15:43:58 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

int check_empty_processes(char *line)
{
	int i;
    int non_space;

	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
		{
            non_space = 0;
			while (line[i] && line[i] != '|')
			{
				if (!is_in_str(WHITESPACES, line[i]))
                {
                    non_space = 1;
                    break ;
                }
				i++;
			}
            if (!non_space)
            {
                if (!line[i])
                    return (1);
                else
                    return (2);
            }
		}
		else
			i++;
	}
    return (0);
}

int count_processes(t_mish *mish)
{
    int i;
    int count;

    i = 0;
    count = 1;
    while (mish->line && mish->line[i])
    {
        if (mish->line[i] == '|')
            count++;
        i++;
    }
    return (count);
}   // empty processes

void    separate_processes(t_mish *mish)
{
	char	**processes;
	int		count;
	int		i;

    if (!check_empty_processes(mish->line))
    {
        mish->error.type = err_token_unexpected; ///////
    }
    count = count_processes(mish);
    mish->p = ft_calloc(count + 1, sizeof(t_process));
    if (!mish->p)
    {
        mish->error.type = err_malloc;
        return (NULL);
    }
    processes = ft_split(mish->line, "|"); // verifier les processes vides
    if (!processes)
    {
        free(mish->p);
        return (NULL);
    }
    else
    {
        i = 0;
        while (i < count)
        {
            i++;
        }
    }
}
