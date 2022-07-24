# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 16:41:36 by bbozorgm          #+#    #+#              #
#    Updated: 2022/07/24 16:55:44 by bbozorgm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
REMOVE = rm -rf

FILES = ./main.c \
		./check_orders.c \
		./lib_1.c \
		./operations.c \
		./set_positions.c \
		./range_upto_5.c \
		./inits.c \
		./values.c \
		./checks.c \
		./free.c \
		./stack_func.c \
		./print.c \
		../Rank1/libft/ft_split.c \
		../Rank1/libft/ft_isdigit.c \
		../Rank1/libft/ft_putendl_fd.c \

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
