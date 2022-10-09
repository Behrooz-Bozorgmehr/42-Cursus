NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
REMOVE = rm -rf

FILES = ./main.c \
		./inits.c \
		./set_stack.c \
		./free.c \
		./checks.c \
		./values.c \
		./print.c \
		./swap_and_push.c \
		./rotates.c \
		./upto_three_sets.c \
		./upto_five_sets.c \
		./quick_sort.c \
		./big_set_a.c \
		./big_set_b.c \
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

