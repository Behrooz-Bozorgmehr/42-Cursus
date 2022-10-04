
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

# define A 1
# define B 2
# define ALL 3

typedef struct s_node	t_node;
typedef struct s_value	t_value;

struct	s_node
{
	int		value;
	t_node	*prev;
	t_node	*next;
};

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;

#endif
