/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_mish.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:56:21 by locharve          #+#    #+#             */
/*   Updated: 2024/04/10 16:07:12 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

static int	count_words(t_mish *mish, char *sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (mish->line[i])
	{
		while (mish->line[i] && is_in_str(sep, mish->line[i]))
			i++;
		if (mish->line[i] && !is_in_str(sep, mish->line[i]))
		{
			i += handle_word(mish, sep, &i);
			count++;
		}
	}
	return (count);
}

static char	*str_piece_cpy(char *str, int start, int end)
{
	char	*tmp;
	int		i;

	tmp = (char *)ft_calloc((end - start + 1), sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	while (start + i < end)
	{
		tmp[i] = str[start + i];
		i++;
	}
	return (tmp);
}

static char	*from_str_to_strs(t_mish *mish, int *i, char *sep)
{
	char	*dst;
	int		j;
	int		tmp;

	while (mish->line[*i] && is_in_str(sep, mish->line[*i]))
		*i += 1;
	j = *i;
	if (mish->line[j] && !is_in_str(sep, mish->line[j]))
	{
		tmp = handle_word(mish, sep, &j);
		if (tmp < 0)
			return (NULL);
		else
			j += tmp;
	}
	dst = str_piece_cpy(mish->line, *i, j);
	*i = j;
	return (dst);
}

void	free_strtab(char **strtab)
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

char	**ft_split_mish(t_mish *mish, char *sep)
{
	char	**dst;
	int		count;
	int		i;
	int		index;

	if (!mish->line)
		return (NULL);
	count = count_words(mish, sep);
	if (mish->error.type)
	{
		print_error(mish); ///////////////////////
		return (NULL);
	}
	dst = (char **)ft_calloc(count + 1, sizeof(char *));
	if (!dst)
		return (NULL);
	i = 0;
	index = 0;
	while (i < count)
	{
		dst[i] = from_str_to_strs(mish, &index, sep);
		if (!dst[i])
		{
			free_strtab(dst);
			return (NULL);
		}
		i++;
	}
	return (dst);
}

/*
int	main(int argc, char **argv)
{
	char	**tab;
	int		i;

	if (argc == 2)
	{
		//printf("count = %d\n", count_words(argv[1], WHITESPACES));
		tab = ft_split(argv[1], WHITESPACES);
		if (tab)
		{
			i = 0;
			while (tab[i])
			{
				printf("|%s|\n", tab[i]);
				i++;
			}
			free_strtab(tab);
		}
	}
	return (0);
}
*/
