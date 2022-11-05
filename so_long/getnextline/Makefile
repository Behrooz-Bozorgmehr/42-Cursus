# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/01 14:40:58 by bbozorgm          #+#    #+#              #
#    Updated: 2022/05/03 11:55:18 by bbozorgm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line 

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ARCHIVE = ar rcs
REMOVE = rm -f

FILES = ../getnextline/get_next_line \
		../getnextline/get_next_line_utils\
		../getnextline/get_next_line_bonus \
		../getnextline/get_next_line_utils_bonus


SRCS = $(addsuffix .c, $(FILES)) 
OBJS = $(addsuffix .o, $(FILES))

.c.o: $(SRCS)
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		$(ARCHIVE) $@ $^

all: $(NAME)

clean:
		$(REMOVE) $(OBJS) 

fclean: 
		clean
		$(REMOVE) $(NAME)
re: clean all

.PHONY: all clean fclean re
