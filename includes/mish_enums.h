/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_enums.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:10:25 by bchene            #+#    #+#             */
/*   Updated: 2024/04/12 15:59:30 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_ENUMS_H
# define MISH_ENUMS_H

typedef enum	e_err_type
{
	err_none,
	err_malloc, // pas necessaire ?
	err_quote_open,
	err_dquote_open,
	err_token_unexpected,
	err_fd_open,
	err_fd_read,
	err_fd_write,
	err_dup,
	err_dup2,
	err_pipe,
	err_fork,
	err_execve,
	err_argument,
	err_split,
	err_invalid_option, // a l'execution ?
	err_other,
	err_unhandled
}	t_err_type;

typedef enum	e_tfile_type
{
	tf_ifile_rdonly,
	tf_ifile_heredoc,
	tf_ofile_creat,
	tf_ofile_append
}	t_tfile_type;

#endif
