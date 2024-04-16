/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:58:13 by bchene            #+#    #+#             */
/*   Updated: 2024/04/10 15:59:02 by bchene           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MISH_PROTOTYPES_H
# define MISH_PROTOTYPES_H

/* mish_10_prompt */
void		mish_prompt(t_mish *mish);

/* mish_01_init */
t_mish		*t_mish_init(t_mish *mish);
t_file		*t_file_init();
int			mish_parse_path(t_mish *mish);

/* mish_02_free */
void		t_mish_free(t_mish *mish);
void		t_file_free(t_file *tf);

/* mish_50_process_init.c */
t_process	*t_process_new(t_mish *mish, int index, char *line);
t_process	*t_process_addnext(t_mish *mish, int index, char *line);
void		t_process_free(t_process *process);
void		t_process_delall(t_mish *mish);
void		t_process_printf(t_process *p);

/* mish_90_ft_strjoin_va.c */
// size_t   len_sum(va_list param);
// char	 *ft_strcat_va(char *dst, va_list param);
char		*ft_strjoin_va(char *str, ...);

/* ft_split_mish.c */
// int  count_words(t_mish *mish, char *sep);
// char *str_piece_cpy(char *str, int start, int end);
// char *from_str_to_strs(char *str, int *i, char *sep);
void		free_strtab(char **strtab);
char		**ft_split_mish(t_mish *mish, char *sep);

/* handle_word.c */
int			handle_quotes(t_mish *mish, int *i, char q);
int			handle_redirections(t_mish *mish, int *i, char r);
int			handle_specials(t_mish *mish, int *i);
int			handle_digits(t_mish *mish, int *i);
int			handle_word(t_mish *mish, char *sep, int *i);

/* handle_pipe.c */
int			handle_pipe(t_mish *mish, int *i);

/* ft_atoll.c */
long long	ft_atoll(char *str);

/* is_in_str.c */
int			is_digit(char c);
int			is_in_str(char *str, char c);

/* is_error.c */
int			is_unexpected_token(t_mish *mish, char *set, char c);
int			is_unexpected_redir(t_mish *mish, char *nbr_addr); //
int			is_bad_fd(t_mish *mish, int i);

/* print_error.c */
void		print_error(t_mish *mish);

/* mish_91_ft_00.c */
char		*ft_strnrchr(char *str, int n, char c);
char		*ft_strempty(char *str);
void		ft_print_split(char **pathlist);
void		ft_printf_strtab(char **str, int size, const char *sep);
void		ft_bzero(void *s, size_t size);
void		*ft_calloc(size_t nmemb, size_t size);

#endif
