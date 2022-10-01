# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 16:41:36 by bbozorgm          #+#    #+#              #
#    Updated: 2022/07/26 17:33:53 by bbozorgm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
REMOVE = rm -rf

FILES = ./main.c \
		./algo_a.c \
		./algo_b.c \
		./check_orders.c \
		./checks.c \
		./fives.c \
		./free.c \
		./inits.c \
		./lib_1.c \
		./operations.c \
		./print.c \
		./push_swap.c \
		./range_upto_5.c \
		./set_positions.c \
		./stack_func.c \
		./three_a.c \
		./three_b.c \
		./under_three.c \
		./values.c \
		../Rank1/libft/ft_split.c \
		../Rank1/libft/ft_isdigit.c \
		../Rank1/libft/ft_putendl_fd.c \
		../Rank1/libft/ft_strlen.c \
		
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
