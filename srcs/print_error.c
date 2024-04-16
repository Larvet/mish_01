/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:14:33 by locharve          #+#    #+#             */
/*   Updated: 2024/04/08 13:14:35 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mish.h"

void    print_error(t_mish *mish)
{
	char	*str;

	if (mish->error.type == __open_quote)
		str = ft_strdup("minishell: open quotes not handled\n");
	else if (mish->error.type == __open_dquote)
		str = ft_strdup("minishell: open double quotes not handled\n");
	else if (mish->error.type == __unexpected_token)
		str = ft_strjoin_va("minishell: syntax error near unexpected token '",
				mish->error.data, "'\n");
	else if (mish->error.type == __bad_fd)
		str = ft_strjoin_va("minishell: ", mish->error.data,
				": Bad file descriptor\n");
	else
		str = ft_strdup("minishell: error ?\n");
	ft_putstr_fd(str, 2);
	mish->error.type = __none;
	free(mish->error.data);
	return ;
}