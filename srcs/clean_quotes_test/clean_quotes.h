/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_quotes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locharve <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:09:06 by locharve          #+#    #+#             */
/*   Updated: 2024/04/11 18:45:40 by locharve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEAN_QUOTES_H
# define CLEAN_QUOTES_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>

# define WHITESPACES_QUOTES "\t\n\v\f\r \'\""

int	is_digit(char c);
int	is_in_str(char *str, char c);

int	ft_isalpha(int c);

size_t	ft_strlen(const char *s);

void	*ft_memmove(void *dest, const void *s, size_t n);

char	*ft_strcpy(char *dst, char *src);

int	ft_strcmp(char *s1, char *s2);

int	ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strndup(char *src, int size);

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);

char	*ft_strchr(const char *s, int c);
char	*ft_strswitnchr(char *s, char src, char dest);

size_t	ft_strlen_until(char *str, char *stop);
char	*get_var_value(char *str, char **name, size_t *len_name);
char	*substitute_var(char *src, char *name, char *var, size_t dst_len);
char	*clean_quotes(char *src, char q);

#endif
