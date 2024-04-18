/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mish_prototypes.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchene <bchene@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 14:58:13 by bchene            #+#    #+#             */
/*   Updated: 2024/04/18 17:15:22 by locharve         ###   ########.fr       */
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
void		t_error_free(t_error *err);
void		t_error_lst_free(t_error **err);
void		strtab_free(char **strtab);

/* mish_04_t_error.c */
t_err_type	mish_t_error_add(t_mish *mish, t_err_type, int en, char *d);

/* mish_50_process_init.c */
t_process	*t_process_new(t_mish *mish, int index, char *line);
t_process	*t_process_addnext(t_mish *mish, int index, char *line);
void		t_process_free(t_process *process);
void		t_process_delall(t_mish *mish);
void		t_process_printf(t_process *p);

/* mish_90_ft_strjoin_va.c */
// 			size_t   len_sum(va_list param);
// 			char	 *ft_strcat_va(char *dst, va_list param);
char		*ft_strjoin_va(char *str, ...);

/* mish_split.c */
// int  	count_words(char *str, char *sep);
// char 	*substr_dup(char *str, int start, int end);
// char 	*from_str_to_strs(char *str, int *i, char *sep);
void		free_strtab(char **strtab);
char		**mish_split(t_process *mish, char *sep);

/* handle_word.c */
int			handle_quotes(char *str, int i, char q);
int			handle_redirections(char *str, int i, char r);
int			handle_specials(char *str, int i);
int			handle_digits(char *str, int i);
int			handle_word(char *str, char *sep, int i);

/* handle_pipe.c */
int			handle_pipe(t_mish *mish, int *i); // obsolete

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

/* ft_split.c */
int			ft_splitsize(char **split);
void		*ft_freesplit(char **split);
// char	**splitit(char *s, char c, char **split, int nb);
int			ft_getnbsplit(char *s, char c);
char		**ft_split(char const *src, char c);

/* ft_strdup.c */
size_t		ft_strlen(const char *str);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s);
char		*ft_strncpy(char *dst, const char *src, size_t n);
char		*ft_strndup(const char *s, size_t n);

/* mish_check_unhandled.c */
int		not_between_quotes(t_mish *mish, char *line, int i);
int			mish_check_unhandled(t_mish *mish);

/* mish_check_syntax_error.c */
// int		is_special_token(char *line, int i);
// char		*next_char_addr(char *str);
// int		dup_err_str(t_mish *mish, char *src, int n, t_err_type_err);
int			mish_check_syntax_error(t_mish *mish);
int			mish_check_open_quotes(t_mish *mish);

/* mish_separate_processes.c */
int			char_count(char *str, char c);
void		process_init_line(t_process **p, char **split, int count);
int			mish_separate_processes(t_mish *mish);

/* mish_clean_quotes.c */
char		*substitute_hub(t_mish *mish, char *src, char *var);
char		*clean_quotes(t_mish *mish, char *src, char q);
void		mish_clean_all_quotes(t_mish *mish, char **p_lines);

/* substitute_fonctions.c */
char		*get_var_value(t_mish *mish, char *var);
char		*dup_substituting(char *src, char *var, char *sub);
char		*substitute_exit_status(t_mish *mish, char *src, char *var);
char		*substitute_digits(t_mish *mish, char *src, char *var);
char		*substitute_var(t_mish *mish, char *src, char *var);

/* mish_fill_processes.c */				// trop de fonctions ; gerer les retours d'erreur
void		file_add_back(t_file **lst, t_file *new);
// char		**strtab_get_io_files(char **split);
// void		process_fill_io_files(t_process *p, char **split);
// void		process_fill_av(t_process *p, char **split);
// int		process_fill(t_process *p);
int			mish_fill_processes(t_mish *mish);

/* mish_91_ft_00.c */
char		*ft_strnrchr(char *str, int n, char c);
char		*ft_strempty(char *str);
void		ft_print_split(char **pathlist);
void		ft_printf_strtab(char **str, int size, const char *sep);
void		ft_bzero(void *s, size_t size);
void		*ft_calloc(size_t nmemb, size_t size);

/* mish_91_ft_01 */
int			is_alphanum_underscore(char c);
size_t		ft_strlen_while(char *str, int f(char));

/* tmp -- libft */
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
void		*ft_memmove(void *dest, const void *src, size_t n);
char		*ft_itoa(int n);

char		*ft_strchr(const char *s, int c);
char		*ft_strswitnchr(char *s, char src, char dest);



#endif
