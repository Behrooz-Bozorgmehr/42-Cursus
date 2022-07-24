
#include "push_swap.h"

int	check_order(t_stack *stack)
{
	int	sorted;
	t_node	*top;

	sorted = 1;
	top = stack->top;
	while (top->next != NULL)
	{
		if (top->val < top->next->val)
			sorted = 1;
		else
		{
			sorted = 0;
			return (sorted);
		}
		top = top->next;
	}
	return (sorted);
}

int	check_reverse_order(t_stack *stack)
{
	int sorted;
	t_node	*top;

	sorted = 1;
	top = stack->top;
	while (top->next != NULL)
	{
		if (top->val > top->next->val)
			sorted = 1;
		else
		{
			sorted = 0;
			return (sorted);
		}
		top = top->next;
	}
	return (sorted);
}
