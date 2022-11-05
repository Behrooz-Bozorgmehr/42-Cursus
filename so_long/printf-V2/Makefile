# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 18:44:21 by bbozorgm          #+#    #+#              #
#    Updated: 2022/05/21 10:53:02 by bbozorgm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCHIVE = ar rcs
REMOVE = rm -rf

FILES = ./ft_printf\
		./ft_printf_lib1\
		./ft_printf_lib2\
		./ft_printf_lib3\
		./ft_printf_lib4\
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
