# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 18:44:21 by bbozorgm          #+#    #+#              #
#    Updated: 2022/05/05 19:02:18 by bbozorgm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCHIVE = ar rcs
REMOVE = rm -rf

FILES = ../printf/ft_printf\
		../printf/ft_printf_lib1\
		../printf/ft_printf_lib2\
		../printf/ft_printf_lib3\
 		../libft/ft_isdigit \
		../libft/ft_strlen \
		../libft/ft_toupper \
		../libft/ft_strndup \
		../libft/ft_itoa \
		../libft/ft_atoi 	

SRCS = $(addsuffix .c, $(FILES)) 
OBJS = $(addsuffix .o, $(FILES)) 

.c.o: $(FILES)
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		$(ARCHIVE) $@ $^

all: $(NAME)

bonus: all

clean: 
		$(REMOVE) $(OBJS)

fclean: clean
		$(REMOVE) $(NAME)
re: clean all

.PHONY: all clean fclean re
