/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_04_t_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:26:53 by bchene            #+#    #+#             */
/*   Updated: 2024/04/16 17:48:57 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void	t_error_add(t_error **lst, t_error *new)
{
	if (lst)
	{
		if (*lst)
			t_error_add(&(*lst)->next, new);
		else
			*lst = new;
	}
	return ;
}

t_error	*t_error_new(t_err_type t, int en, char *d)
{
	t_error	*new;

	new = ft_calloc(1, sizeof(t_error));
	if (new)
	{
		new->type = t;
		new->err_no = en;
		new->data = ft_strdup(d);
		new->next = NULL;
	}
	return (new);
}

t_err_type	mish_t_error_add(t_mish *mish, t_err_type t, int en, char *d)
{
	t_error	*new;

	new = t_error_new(t, en, d);
	if (new)
		t_error_add(&mish->error, new);
	else
		return (err_malloc);
	return (t);
}
/*
void	mish_t_error_free(t_mish *mish)
{

}

mish_t_error_add(mish, err_malloc, errno, "malloc de fd");
*/
