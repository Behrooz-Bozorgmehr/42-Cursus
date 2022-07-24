
#include "push_swap.h"

void	print_msg()
{
	write(STDERR, "Error\n", 6);
	exit(0);
}

void	print_stack(t_stack *stack)
{
	t_node *top;
	t_node *fix;
	
	fix = stack->top;
	while (stack->top != NULL)
	{
		top = stack->top;
		printf("val : %d\t, pos : %d\n", top->val, top->pos);
		stack->top = stack->top->next;
	}
	stack->top = fix;
}
