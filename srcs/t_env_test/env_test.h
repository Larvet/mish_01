/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_test.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 15:14:44 by locharve          #+#    #+#             */
/*   Updated: 2024/04/15 15:16:18 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_TEST_H
# define ENV_TEST_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct	s_env
{
	char			*str;
	struct s_env	*next;
}	t_env;

typedef struct	s_mish
{
	t_env	*env;
}	t_mish;

#endif
