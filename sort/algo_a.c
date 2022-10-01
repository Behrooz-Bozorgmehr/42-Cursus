
#include "push_swap.h"

static int	handle_stack_end(t_stack *a, t_stack *b, int n)
{
	print_string("algo_a.c, func:handle_stack_end");
	if (n <= 3)
	{
		under_three_handler(a, b, 'A', n);
		return (0);
	}
	else if (n == 5)
	{
		sort_five_handler(a, b, 'A', 5);
		return (0);
	}
	else
		return (1);
}

void	push_rotate_a(t_stack *a, t_stack *b, t_operation *op)
{

	print_string("algo_a.c, func: push_rotate_a");
	if (a->top->val > op->pvt_a)
	{
		rotate(a, 'A');
		op->ra++;
	}
	else
	{
		pop_push(b, a, 'B');
		op->pb++;
		if (b->top->val > op->pvt_b)
		{
			rotate(b, 'B');
			op->rb++;
		}
	}
}

void	undo_ra_in_a(t_stack *a, t_stack *b, int *count, t_operation *op)
{
	print_string("algo_a.c, func: undo_ra_in_a");
	int	rrr;
	int	rest;

	rrr = op->rb;
	rest = op->ra - rrr;
	if ((*count) > 0)
	{
		while (rrr--)
			rotate_both_backward(a, b);
		while (rest--)
			rotate_backward(a, 'A');
	}
	else
	{
		while (rrr--)
		{
			print_string("algo_a.c, func: undo_ra_in_a, before rotate backward");
			rotate_backward(b, 'B');
		}
	}
}

void	undo_rb_in_a(t_stack *a, t_stack *b, int *count, t_operation *op)
{
	print_string("algo_a.c, func: undo_rb_in_a");
	int	rrr;
	int	rest;

	rrr = op->ra;
	rest = op->rb - rrr;
	if ((*count) > 0)
	{
		while (rrr--)
			rotate_both_backward(a, b);
		while (rest--)
			rotate_backward(b, 'B');
	}
	else
	{
		rrr = op->rb;
		while (rrr--)
			rotate_backward(b, 'B');
	}
}

void	moves_a_2_b(t_stack *a, t_stack *b, int n, int *count)
{
//	int		tmp;
	t_operation op;
	print_string("algo_a.c, func:move_a_2_b");
	if (handle_stack_end(a, b, n) == 0)
		return ;
	init_ops(&op);
	init_pivots(a, &op, n);
//	tmp = n;
	while (n--)
		push_rotate_a(a, b, &op);
	if (op.ra > op.rb)
		undo_ra_in_a(a, b, count, &op);
	else
		undo_rb_in_a(a, b, count, &op);
	moves_a_2_b(a, b, op.ra, count);
	moves_b_2_a(a, b, op.rb, count);
	moves_b_2_a(a, b, (op.pb - op.rb), count);
}
