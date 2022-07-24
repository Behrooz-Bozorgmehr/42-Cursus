
#include "push_swap.h"

int	swap(t_stack **stack, char flag)
{
	t_node	*top;
	t_node	*next;

	next = (*stack)->top;
	top = (*stack)->top->next;
	if (next != NULL && top != NULL)
	{
		if (top->next != NULL)
			top->next->prev = next;
		next->next = top->next;
		next->prev = top;
		top->prev = NULL;
		top->next = next;
		if (flag == 'A')
			write(STDOUT, "sa\n", 3);
		else if (flag == 'B')
			write(STDOUT, "sb\n", 3);
		return (1);
	}
	return (0);
}

int	rotate(t_stack *stack, char flag)
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
		return (1);
	}
	return (0);
}

int	rotate_backward(t_stack *stack, char flag)
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
		return (1);
	}
	return (0);
}

int	pop_push(t_stack *dst, t_stack *src, char dst_flag)
{
	t_node	*temp;
	
	if (src != NULL)
	{
		temp = src->top;
		if (temp->next != NULL)
			temp->next->prev = NULL;
		temp->next = NULL;
		if (dst->top != NULL)
		{	
			temp->next = dst->top;
			dst->top->prev = temp;
		}
		else
			dst->top = temp;
		if (dst_flag == 'A')
			write(STDOUT, "pa\n", 3);
		else if (dst_flag == 'B')
			write(STDOUT, "pb\n", 3);
		return (1);
	}
	return (0);
}
