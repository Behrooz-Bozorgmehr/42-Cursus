#include "push_swap.h"

void	print_error()
{
	ft_putendl_fd("Error", 2);
	exit(0);
}

void 	print_string(char *str)
{
	ft_putendl_fd(str, 1);
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
		stack->top = stack->top->next;
	}
	stack->top = fix;
}

void	print_stack_details(t_stack *stack, char flag){

	t_node *top;
	t_node *fix;
	
	printf("stack: %c\t stack_size: %d\n", flag, stack->size);
	fix = stack->top;
	while (stack->top != NULL)
	{
		top = stack->top;
		printf("val : %d\t, node : %p\t\t next : %p\t\t prev :%p\n", top->val, top, top->next, top->prev);
		stack->top = stack->top->next;
	}
	stack->top = fix;
}