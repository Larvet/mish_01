/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_04_t_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 17:26:53 by bchene            #+#    #+#             */
/*   Updated: 2024/04/12 18:30:08 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

t_err_type	mish_t_error_add(t_mish *mish, t_err_type t, int en, char *d)
{
	while (mish->error)
		mish->error = mish->error->next;
	mish->error = ft_calloc(1, sizeof(t_error));	// malloc ?!
	if (mish->error)
	{
		mish->error.type = t;
		mish->error.err_no = en;
		mish->error.data = ft_strdup(d);						// strdup pendant l'appel?
	}
	else
		return (err_malloc);						// ?
	return (t);
}
/*
void	mish_t_error_free(t_mish *mish)
{

}

mish_t_error_add(mish, err_malloc, errno, "malloc de fd");
*/