#include "push_swap.h"

int	swap(t_stack *stack, char flag)

{
	t_node	*top;
	t_node	*next;

	next = (stack)->top;
	top = (stack)->top->next;
	if (next != NULL && top != NULL)
	{
		if (top->next != NULL)
			top->next->prev = next;
		next->next = top->next;
		next->prev = top;
		top->prev = NULL;
		top->next = next;
		(stack)->top = top;
		if (flag == 'A')
			print_string("sa");
		else if (flag == 'B')
			print_string("sb");
		return (1);
	}
	return (0);
}

int	init_dst(t_stack *dst, t_stack *src)
{
	dst->top = src->top;
	dst->bot = dst->top;
	if(src->size == 1)
	{
		src->top = NULL;
		src->bot = NULL;
	}
	else
	{
		src->top = src->top->next;
		src->top->prev = NULL;
	}
	dst->top->prev = NULL;
	dst->top->next = NULL;
	return (1);
}

int	push_dst(t_stack *dst, t_stack *src)
{
	dst->top->prev = src->top;
	if (src->size == 1)
	{
		src->top = NULL;
		src->bot = src->top;
	}
	else
	{
		src->top->next->prev = NULL;
		src->top = src->top->next;
		src->top->prev = NULL;
	}
	dst->top->prev->next = dst->top;
	dst->top = dst->top->prev;
	

	return (1);
}

int	pop_push(t_stack *dst, t_stack *src, char dst_flag)
{
	if (src->top != NULL)
	{
		if(dst->size == 0)
			init_dst(dst, src);
		else
			push_dst(dst, src);
		dst->size++;
		src->size--;
		if (dst_flag == 'A')
		    print_string("pa");
		else if (dst_flag == 'B')
		    print_string("pb");
		return (1);
	}
	return (0);
}



