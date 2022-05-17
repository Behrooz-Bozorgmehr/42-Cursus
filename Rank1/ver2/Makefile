# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 18:44:21 by bbozorgm          #+#    #+#              #
#    Updated: 2022/05/17 21:11:57 by bbozorgm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCHIVE = ar rcs
REMOVE = rm -rf

FILES = ../ver2/ft_printf\
		../ver2/ft_printf_lib1\
		../ver2/ft_printf_lib2\
		../ver2/ft_printf_lib3\
		../libft/ft_strlen\
		../libft/ft_toupper\
		../libft/ft_itoa\
		../libft/ft_atoi\
		../libft/ft_isdigit


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
