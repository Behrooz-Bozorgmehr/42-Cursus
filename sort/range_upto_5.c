
#include "push_swap.h"

void	algo_3(t_stack *a)
{
	t_node	*top;
	t_node	*bot;

	top = a->top;
	bot = a->bot;
	if (top->val < bot->val && top->next->val > bot->val)
	{
		rotate_backward(a, 'A');
		swap(a, 'A');
	}
	else if (top->val > top->next->val && bot->val > top->val)
		swap(a, 'A');
	else if (top->val < top->next->val && top->val > bot->val)
	   rotate_backward(a, 'A');
	else if (top->val > top->next->val && top->next->val > bot->val)
	{
		swap(a, 'A');
		rotate_backward(a, 'A');
	}
	else if (top->val > top->next->val && top->next->val < bot->val)
	{
		rotate_backward(a, 'A');
		rotate_backward(a, 'A');
	}
}

void	algo_5(t_stack *a, t_stack *b)
{
	int	val;
	int	n_val;
	int	p_val;
	int size;

	size = a->size;
	while (check_order(a) == 0 || a->size != size)
	{
		while (a->size > 3 && check_order(a) == 0)
		{
			val = a->top->val;
			n_val = a->top->next->val;
			p_val = a->bot->val;
			if (val < n_val && val < p_val)
				pop_push(b, a, 'B');
			else if (val > n_val)
				swap(a, 'A');
			else if (p_val < val)
				rotate_backward(a, 'A');
		}
		if (a->size == 3)
			algo_3(a);
		if (b->size == 2 && b->top->val < b->top->next->val)
			swap(b, 'B');
		else if (b->top != NULL)
			pop_push(a, b, 'A');
	}
}
