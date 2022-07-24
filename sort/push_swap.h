

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


#include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../Rank1/libft/libft.h"

# define STDOUT 1
# define STDERR 2

# define MAX_INT 2147483647
# define MIN_INT -2147483648


typedef struct s_operation	t_operation;
typedef struct s_node		t_node;
typedef struct s_stack		t_stack;


typedef struct	s_operation
{
	int	ra;
	int	rb;
	int	pa;
	int	pb;
	int	pvt_a;
	int pvt_b;
}	t_operation;

typedef struct s_stack
{
	int		size;
	t_node	*top;
	t_node	*bot;
}	t_stack;

typedef struct	s_node
{
	int		val;
	int		pos;
	t_node	*prev;
	t_node	*next;
}	t_node;


void	print_msg();
void	init_ops(t_operation *op);
void	init_pivots(t_stack *stack, t_operation *op, int n); 
t_stack	*init_stack();
t_node	*init_node();

void	free_stack(t_stack	*stack);
void	free_all(t_stack *a, t_stack *b);

int		atoi_func(char *str);
void	fill_stack(t_stack *stack, char *argv[], int size);
int		set_node(t_stack **stack, t_node **node, char *str);
void	set_connections(t_stack **stack, t_node **node, t_node **temp);

int		maximum(t_node *node, int n);
int		minimum(t_node *node, int n);
int		middle_5(t_node *node);

int		*define_position(t_node *node, int size);
void	set_position(t_node *node, int ptr[], int size);
void	quick_sort(int arg[], int start, int end);
int		partition(int arg[], int start, int end);

int		is_number(char *str);
int		is_doublicated(t_stack *stack);
int		doublicated(int *arr, int size);
t_stack *do_checks(t_stack *stack);

void	algo_3(t_stack *a);

int		swap(t_stack **stack, char flag);
int		rotate(t_stack *stack, char flag);
int		rotate_backward(t_stack *stack, char flag);


void	print_stack(t_stack *stack);


#endif /* PUSH_SWAP_H */