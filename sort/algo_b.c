
#include "push_swap.h"

static int	handle_stack_end(t_stack *a, t_stack *b, int n)
{
	if (n <= 3)
	{
		under_three_handler(a, b, 'B', n);
		return (0);
	}
	else if (n == 5)
	{
		sort_five_handler(a, b, 'B', 5);
		return (0);
	}
	else
		return (1);
}

void	push_rotate_b(t_stack *a, t_stack *b, t_operation *op)
{
	if (b->top->val <= op->pvt_a)
	{
		rotate(b, 'B');
		op->rb++;
	}
	else
	{
		pop_push(a, b, 'A');
		op->pa++;
		if (a->top->val <= op->pvt_b)
		{
			rotate(a, 'A');
			op->ra++;
		}

	}
}

void	undo_ra_in_b(t_stack *a, t_stack *b, t_operation *op)
{
	int	rrr;
	int	rest;

	rrr = op->rb;
	rest = op->ra - rrr;
	while (rrr--)
		rotate_both_backward(a, b);
	while (rest--)
		rotate_backward(a, 'A');
}

void	undo_rb_in_b(t_stack *a, t_stack *b, t_operation *op)
{
	int	rrr;
	int	rest;

	rrr = op->ra;
	rest = op->rb - rrr;
	while (rrr--)
		rotate_both_backward(a, b);
	while (rest--)
		rotate_backward(b, 'B');
}

void	moves_b_2_a(t_stack *a, t_stack *b, int n, int *count)
{
//	int		tmp;
	t_operation	op;

	(*count)++;
	if (handle_stack_end(a, b, n) == 0)
		return ;
	init_ops(&op);
	init_pivots(b, &op, n);
//	tmp = n;
	while (n--)
		push_rotate_b(a, b, &op);
	moves_a_2_b(a, b, (op.pa - op.ra), count);
	if (op.ra > op.rb)
		undo_ra_in_b(a, b, &op);
	else
		undo_rb_in_b(a, b, &op);
	moves_a_2_b(a, b, op.ra, count);
	moves_b_2_a(a, b, op.rb, count);
}
