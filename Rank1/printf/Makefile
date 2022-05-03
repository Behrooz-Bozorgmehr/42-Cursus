# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 18:44:21 by bbozorgm          #+#    #+#              #
#    Updated: 2022/04/28 20:30:12 by bbozorgm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCHIVE = ar rcs
REMOVE = rm -rf

FILES = ../printf/ft_printf\
		../libft/ft_isdigit \
		../libft/ft_strlen \
		../libft/ft_toupper \
		../libft/ft_strndup \
		../libft/ft_itoa 

SRCS = $(addsuffix .c, $(FILES)) 
OBJS = $(addsuffix .o, $(FILES))

.c.o: $(FILES)
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		$(ARCHIVE) $@ $^

all: $(NAME)

clean: $(REMOVE) $(OBJS)

fclean: clean
		$(REMOVE) $(NAME)
re: clean all

.PHONY: all clean fclean re
