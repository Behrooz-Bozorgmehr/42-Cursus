#include "push_swap.h"

void	pop_from_b(t_stack *a, t_stack *b, t_operation *ops)
{
	if (b->top->val <= ops->pvt_b)
	{
		rotate(b, 'B');
		ops->rb++;
	}
	else
	{
		pop_push(a, b, 'A');
		ops->pa++;
		if (a->top->val <= ops->pvt_a)
		{
			rotate(a, 'A');
			ops->ra++;
		}
	}
}

void	return2origin_ab(t_stack *a, t_stack *b, t_operation *ops)
{
	int	rot_back;
	int	rest;

	rot_back = ops->rb;
	rest = ops->ra - rot_back;
	while (rot_back--)
		rotate_both_backward(a, b);
	while (rest--)
		rotate_backward(a, 'A');
}

void	return2origin_bb(t_stack *a, t_stack *b, t_operation *ops)
{
	int	rot_back;
	int	rest;

	rot_back = ops->ra;
	rest = ops->rb - rot_back;
	while (rot_back--)
		rotate_both_backward(a, b);
	while (rest--)
		rotate_backward(b, 'B');
}

void	moves_b2a(t_stack *a, t_stack *b, int size, int *count)
{
	t_operation	ops;

	(*count)++;
	if (end_stack_handler(a, b, 'B',size) == 1)
		return ;
	init_ops(&ops);
	init_pivots(b, &ops, size);
	while (size--)
		pop_from_b(a, b, &ops);
	moves_a2b(a, b, (ops.pa - ops.ra), count);
	if (ops.ra > ops.rb)
		return2origin_ab(a, b, &ops);
	else
		return2origin_bb(a, b, &ops);
	moves_a2b(a, b, ops.ra, count);
	moves_b2a(a, b, ops.rb, count);
}
