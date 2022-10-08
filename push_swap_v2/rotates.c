#include "push_swap.h"

int	rotate(t_stack *stack, char flag)
{
	t_node	*top;
	t_node	*new_top;

	if (stack->size < 2)
		return (0);
	top = stack->top;
	new_top = stack->top->next;
	stack->bot->next = top;
	top->prev = stack->bot;
	top->next = NULL;
	stack->bot = top;
	stack->top = new_top;
	stack->top->prev = NULL;
	if (flag == 'A')
		print_string("ra");
	else if (flag == 'B')
		print_string("rb");
	return (1);
}

int	rotate_backward(t_stack *stack, char flag)
{
	t_node	*bottom;
	t_node	*new_bot;

	if (stack->size < 2)
		return (0);
	bottom = stack->bot;
	new_bot = stack->bot->prev;
	stack->top->prev = bottom;
	bottom->next = stack->top;
	bottom->prev = NULL;
	stack->top = bottom;
	stack->bot = new_bot;
	stack->bot->next = NULL;
	if (flag == 'A')
		print_string("rra");
	else if (flag == 'B')
		print_string("rrb");
	return (1);
}

int	rotate_both(t_stack *a, t_stack *b)
{
	rotate(a, 'A');
	rotate(b, 'B');
	return (1);
}

int	rotate_both_backward(t_stack *a, t_stack *b)
{
	rotate_backward(a, 'A');
	rotate_backward(b, 'B');
	return (1);
}