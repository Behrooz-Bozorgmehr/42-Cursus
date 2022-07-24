
#include "push_swap.h"

void	swap(t_stack *stack, char flag)
{
	t_node	*top;
	t_node	*next;

	next = stack->top;
	top = stack->next;
	if (next != NULL && top != NULL)	
	{
		top->next->prev = next;
		next->next = top->next;
		next->prev = top;
		top->prev = NULL;
		top->next = next;
		if (flag == 'A')
			write(STDOUT, "sa\n", 3);
		else if (flag == 'B')
			write(STDOUT, "sb\n", 3);
	}
}

void	rotate(t_stack *stack, char flag)
{
	t_node	*bot;
	t_node	*top;

	top = stack->top;
	bot = stack->bot;
	if (top != NULL && top->next != NULL)
	{
		bot->prev->next = top;
		bot = top;
		top = top->next;
		top->prev = NULL;
		bot->next = NULL;
		if (flag == 'A')
			write(STDOUT, "ra\n", 3);
		else if (flag == 'B')
			write(STDOUT, "rb\n", 3);
	}
}

void	rotate_backward(t_stack *stack, char flag)
{
	t_node	*bot;
	t_node	*top;

	top = stack->top;
	bot = stack->bot;
	if (top != NULL && top->next != NULL)
	{
		bot->next = top->next;
		top = bot;
		bot = bot->prev;
		bot->next = NULL;
		top->prev = NULL;
		if (flag == 'A')
			write(STDOUT, "rra\n", 4);
		else if (flag == 'B')
			write(STDOUT, "rrb\n", 4);
	}
	
}
