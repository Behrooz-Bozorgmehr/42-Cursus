
#include "push_swap.h"
#include <string.h>

void	print_msg()
{
	write(STDERR, "Error\n", 6);
//	ft_putendl_fd("Error", 2);
	exit(1);
}

void 	print_string(char *str)
{
		write(STDOUT, str, ft_strlen(str));
		write(STDOUT, "\n", 1);
}
void	print_stack(t_stack *stack)
{
	t_node *top;
	t_node *fix;
	
	fix = stack->top;
	while (stack->top != NULL)
	{
		top = stack->top;
		printf("val : %d\n", top->val);
		//printf("val : %d\t, pos : %d\n", top->val, top->pos);
		stack->top = stack->top->next;
	}
	stack->top = fix;
}

