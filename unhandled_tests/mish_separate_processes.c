# include "mish.h"

int		char_count(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

void	process_init_line(t_process **p, char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		(*p + i)->line = split[i];
		i++;
	}
	return ;
}

void	mish_init_p_mish(t_mish *mish)
{
	int	i;

	i = 0;
	while (i < mish->nb)
	{
		mish->p[i].mish = mish;
		i++;
	}
	return ;
}

int	mish_separate_processes(t_mish *mish)
{
	char	**processes;
	int		count;
	
	processes = NULL;
	if (!mish_check_syntax_error(mish) && !mish_check_unhandled(mish)
			&& !mish_check_open_quotes(mish))
	{
		count = char_count(mish->line, '|') + 1;
		mish->p = ft_calloc(count, sizeof(*(mish->p))); // malloc
		if (mish->p)
		{
			processes = ft_split(mish->line, '|'); // malloc
			if (processes)
			{
				mish->nb = count;
				process_init_line(&mish->p, processes, count);
				mish_init_p_mish(mish);
				free(processes);
			}
		}
		else
			return (0);
	}
	return (1);
}
