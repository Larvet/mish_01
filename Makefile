# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bchene <bchene@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 16:18:12 by bchene            #+#    #+#              #
#    Updated: 2024/04/10 16:22:36 by bchene           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		minishell

SRCS_DIR =  ./srcs
OBJS_DIR =  ./objs

CC =        cc
CFLAGS =    -Wall -Wextra -Werror -g

HEADERS =	-I ./includes -I ./libs/libft
LIBS =		./libs/libft/libft.a

SRCS =	mish_00_main.c	mish_01_init.c	mish_02_free.c	mish_03_signals.c \
		mish_10_prompt.c \
		mish_50_process_init.c	mish_51_process_parse.c	mish_52_process_pipe.c \
		mish_53_process_exec.c	mish_59_pipex.c \
		ft_split_mish.c	handle_word.c	is_in_str.c	handle_pipe.c \
		print_error.c	is_error.c	ft_atoll.c \
		mish_90_ft_strjoin_va.c		mish_91_ft_00.c

OBJS =	$(addprefix $(OBJS_DIR)/, $(SRCS:.c=.o))

all: libft $(NAME)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	test -d $(OBJS_DIR) || mkdir $(OBJS_DIR)
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME) -lreadline
	
libft:
	make --no-print-directory -C ./libs/libft

gdb: all
	gdb -tui $(NAME)

valgrind: all
	valgrind --show-leak-kinds=all --leak-check=full --track-origins=yes ./$(NAME)

run: all
	./$(NAME)

clean:
	rm -rf $(OBJS_DIR)
	make --no-print-directory -C ./libs/libft clean

fclean: clean
	rm -rf $(NAME)
	make --no-print-directory -C ./libs/libft fclean

re: clean all

.PHONY: all, clean, fclean, re, libft, gdb, valgrind, run
