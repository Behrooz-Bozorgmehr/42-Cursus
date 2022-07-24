
#include "push_swap.h"

void	lst_add_front(t_stack *stack, int val, int pos)
{
	t_node	*front;

	front = init_node();
	front->val = val;
	front->pos = pos;
	if (stack->top == NULL)
		stack->top = front;
	else
	{
		stack->top->prev = front;
		front->next = stack->top;
		stack->top = front;
	}
	stack->size++;
}

