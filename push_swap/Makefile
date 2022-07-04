# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 16:41:36 by bbozorgm          #+#    #+#              #
#    Updated: 2022/06/29 19:54:03 by bbozorgm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
REMOVE = rm -rf

FILES = ./main.c \
		./push_swap.c \
		./lib_1.c \
		./operations_1.c \
		./operations_2.c \
		./operations_3.c \
		./operations_4.c \
		./operations_5.c \
		./algo.c \
		../Rank1/libft/ft_split.c
OBJS = $(FILES:.c=.o)
.c.o: $(FILES)
		$(CC) $(CFLAGS) -c -o $@ $<

$(NAME):
	$(CC) $(FILES) -o $(NAME)

all: $(NAME)

#bonus: all

clean:
		$(REMOVE) $(OBJS)

fclean: clean
		$(REMOVE) $(NAME)
re: clean all

.PHONY: all clean fclean re
