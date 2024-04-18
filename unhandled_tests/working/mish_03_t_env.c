/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_03_t_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 19:07:17 by bchene            #+#    #+#             */
/*   Updated: 2024/04/12 17:58:46 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_env	*t_env_new(char *str)
{
	t_env   *new;

	new = malloc(sizeof(t_env));
	if (new == NULL)
		return (NULL);
	new->str = ft_strdup(str);
	new->next = NULL;
	return (new);
}

t_env	*t_env_add(t_env **env, char *str)
{
	t_env   *new;
	t_env	*cur;

	new = t_env_new(str);
	if (new == NULL)
		return (NULL);
	if (*env == NULL)
	{
		*env = new;
		return (new);
	}
	cur = *env;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	return (new);
}

void	t_env_del(t_env *env)
{
	if (env->str)
		free (env->str);
	free (env);
}

void	*t_env_free(t_env *env)
{
	if (env)
	{
		if (env->next)
			t_env_free(env->next);
		t_env_del(env);
	}
}

int	t_env_remove(t_env **env, t_env *to_remove)
{
	t_env	*cur;

	if (env == NULL || to_remove == NULL)
		return (-1);
	cur = *env;
	if (cur == to_remove)
	{
		*env = cur->next;
		t_env_del(to_remove);
		return (0);
	}
	while (cur->next && (cur->next != to_remove))
		cur = cur->next;
	if (cur->next == to_remove)
	{
		cur->next = to_remove->next;
		t_env_del(to_remove);
		return (0);
	}
	return (1);
}

t_env	*t_env_getvar(t_env *env, char *var)
{
	if (env == NULL || var == NULL)
		return (NULL);
	while (env->next)
	{
		if (ft_strncmp(env->str, var, ft_strlen(var)) && 
		ft_strncmp((env->str) + ft_strlen(var), "=", 1))
			return (env);
		env = env->next;
	}
	if (ft_strncmp(env->str, var, ft_strlen(var)) && 
	ft_strncmp((env->str) + ft_strlen(var), "=", 1))
		return (env);
	return (NULL);
}

char	*t_env_getdata(t_env *env, char *var)
{
	t_env	*varenv;

	if (env == NULL || var == NULL)
		return (NULL);
	varenv = t_env_getvar(env, var);
	if (varenv)
		return (varenv->str + ft_strlen(var) + 1);
	return (NULL);
}

int	t_env_setstr(t_env *env, char *var, char *value)
{
	t_env	*varenv;
	char	*str;

	if (env == NULL || var == NULL || value == NULL)
		return (-1);
	str = ft_strempty(str);
	str = ft_strjointo(str, var);
	str = ft_strjointo(str, "=");
	str = ft_strjointo(str, value);
	varenv = t_env_getvar(env, var);
	if (varenv)
	{
		free(varenv);
		varenv = strdup(str);
	}
	else
		t_env_add(&env, str);
	free(str);
	return (0);
}

char	*mish_env_get(t_mish *mish, char *var)
{
	char *str;

	str = t_env_getdata(mish->env, var);
	return (str);
}

int	mish_env_set(t_mish *mish, char *var, char *value)
{
	int ret;

	if (t_env_getvar(mish->env, var))
		ret = t_env_setstr(mish->env, var, value);
	else
		ret = -1;
	return (ret);
}

int	mish_env_add(t_mish *mish, char *var, char *value)
{
	int ret;
	
	ret = t_env_setstr(mish->env, var, value);
	return (ret);
}

char	*mish_unset_get(t_mish *mish, char *var)
{
	char *str;

	str = t_env_getdata(mish->unset, var);
	return (str);
}

int	mish_unset_set(t_mish *mish, char *var, char *value)
{
	int ret;

	ret = t_env_setstr(mish->unset, var, value);
	return (ret);
}

void	mish_exit_status_set(t_mish *mish, char *value)
{
	mish_unset_set(mish, "?", value);
}

void	mish_exit_status_get(t_mish *mish, char *value)
{
	char *exit_status;

	exit_status = mish_unset_get(mish, "?");
	return (exit_status);
}

void	mish_env_init(t_mish *mish, char **env)
{
	while (*env)
	{
		t_env_add(&(mish->env), *env);
		*env++;
	}
	t_env_add(&(mish->unset), "?=0");
}

void	t_env_print(t_env *env)
{
	if (env && env->str)
	{
		ft_printf("%s\n", env->str);
		t_env_print(env->next);
	}
}

void	mish_print_env(t_mish *mish)
{
	t_env_print(mish->env);
}
