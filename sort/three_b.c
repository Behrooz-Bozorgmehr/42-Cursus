
#include "push_swap.h"

void	three_top_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		rotate(b, 'B');
		if (b->top->next->val == max)
			swap(b, 'B');
	}
	else
	{
		swap(b, 'B');
		rotate(b, 'B');
		swap(b, 'B');
		rotate_backward(b, 'B');
		if (b->top->next->val == max)
			swap(b, 'B');
	}
}

void	three_mid_min_b(t_stack *b, int max)
{
	if (b->size == 3)
	{
		rotate_backward(b, 'B');
		if (b->top->next->val == max)
			swap(b, 'B');
	}
	else
	{
		rotate(b, 'B');
		swap(b, 'B');
		rotate_backward(b, 'B');
		if (b->top->next->val == max)
			swap(b, 'B');
	}
}

void	three_bottom_min_b(t_stack *b, int max)
{
	if (b->top->next->val == max)
		swap(b, 'B');
}

void	three_handler_b(t_stack *a, t_stack *b, int n)
{
	int	min;
	int	max;

	min = minimum(b->top, n);
	max = maximum(b->top, n);
	if (b->top->val == min)
		three_top_min_b(b, max);
	else if (b->top->next->val == min)
		three_mid_min_b(b, max);
	else if (b->top->next->next->val == min)
		three_bottom_min_b(b, max);
	pop_push(a, b, 'A');
	pop_push(a, b, 'A');
	pop_push(a, b, 'A');
}
