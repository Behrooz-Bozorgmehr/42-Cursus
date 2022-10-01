
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
		
	bot = stack->top;
	top = stack->bot;
	if (stack->size == 1)
		return (0);
	if (stack->size == 2)
	{
		stack->top = top;
		stack->bot = bot;
		stack->top->next = bot;
		stack->bot->prev = top;	
	}
	else if(stack->size > 2)
	{
		stack->bot->next = stack->top;
		stack->top->prev = stack->bot;
		stack->bot = stack->top;
		stack->top = stack->top->next;
		//print_stack(stack);	
	}	
	stack->top->prev = NULL;
	stack->bot->next = NULL;
	if (flag == 'A')
		write(STDOUT, "ra\n", 3);
	else if (flag == 'B')
		write(STDOUT, "rb\n", 3);
	return (1);
}

int	rotate_backward(t_stack *stack, char flag)
{
	//print_string("operations.c, func: rotate_backward");
	t_node	*bot;
	t_node	*top;
	char c = 'a' + stack->size;
	write(1, &c, 1);
	write(1, "\n", 1);
	top = stack->bot;
	bot = stack->top;
	if (stack->size == 1)
		return (0);
	else if (stack->size == 2)
	{
		print_string("operations.c, func: rotate_backward_size 2");
		stack->top = top;
		stack->bot = bot;
		stack->top->next = bot;
		stack->bot->prev = top;	
	}
	else if(stack->size > 2)
	{
		print_string("operations.c, func: rotate_backward_size > 2");
	
		stack->bot = top->prev;
		stack->top->next->prev = top;
		top->next = stack->top;
		stack->top = top;

		print_stack(stack);	
	}	
	stack->top->prev = NULL;
	stack->bot->next = NULL;
	if (flag == 'A')
		write(STDOUT, "rra\n", 4);
	else if (flag == 'B')
		write(STDOUT, "rrb\n", 4);
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

int	pop_push(t_stack *dst, t_stack *src, char dst_flag)
{
	print_string("operations.c, func:pop_push");
	t_node	*head;

	

	if (src != NULL)
	{
		head = src->top; 
		if (head->next != NULL)
		{
			src->top = src->top->next;
			src->top->prev = NULL;
		}
		else 
			src->top = NULL;
		lst_add_front(dst, head->val, head->pos);
	//	free(head);
//		head = NULL;
		src->size--;
		
		print_string("source:\n");
		print_stack(src);
		print_string("dst:\n");
		write(1, &dst_flag, 1);
		print_string(":\n");
		print_stack(dst);
		if (dst_flag == 'A')
			write(STDOUT, "pa\n", 3);
		else if (dst_flag == 'B')
			write(STDOUT, "pb\n", 3);
		return (1);
	}
	return (0);
}
