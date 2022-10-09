

#include "push_swap.h"

void	three_top_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->next->val == max)
		{
			rotate_backward(a, 'A');
			swap(a, 'A');
		}
	}
	else
	{
		if (a->top->next->val == max)
		{
			rotate(a, 'A');
			swap(a, 'A');
			rotate_backward(a, 'A');
		}
	}
}

void	three_mid_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->bot->val == max)
			swap(a, 'A');
		else
			rotate(a, 'A');
	}
	else
	{
		swap(a, 'A');
		if (a->top->next->val == max)
		{
			rotate(a, 'A');
			swap(a, 'A');
			rotate_backward(a, 'A');
		}
	}
}

void	three_bottom_min_a(t_stack *a, int max)
{
	if (a->size == 3)
	{
		if (a->top->val == max)
			swap(a, 'A');
		rotate_backward(a, 'A');
	}
	else
	{
		if (a->top->val == max)
			swap(a, 'A');
		rotate(a, 'A');
		swap(a, 'A');
		rotate_backward(a, 'A');
		swap(a, 'A');
	}
}

void	three_handler_a(t_stack *a, int size)
{
	int	min;
	int	max;

	min = minimum(a->top, size);
	max = maximum(a->top, size);
	if (a->top->val == min)
		three_top_min_a(a, max);
	else if (a->top->next->val == min)
		three_mid_min_a(a, max);
	else if (a->top->next->next->val == min)
		three_bottom_min_a(a, max);
}
