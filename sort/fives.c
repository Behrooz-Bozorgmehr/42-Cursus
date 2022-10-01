
#include "push_swap.h"

void	sort_five_handler_a(t_stack *a, t_stack *b, int n)
{
	//print_string("fives.c, func:sort_five_handler_a");
	int	mid;
	int	push;
	int	rot;

	push = 0;
	rot = 0;
	mid = middle_5(a->top);
	while (n--)
	{
		if (a->top->val < mid)
		{
			print_string("fives.c, func:sort_five_handler_a, push to b");
			pop_push(b, a, 'B');
			push++;
		}
		else
		{
			rotate(a, 'A');
			rot++;
		}
		if (push == 2)
			break ;
	}
	while (rot--)
	{
		print_string("fives.c, func:sort_five_handler_a, rotatebackward");
		rotate_backward(a, 'A');

	}
}

void	sort_five_handler_b(t_stack *a, t_stack *b, int n)
{
	int	mid;
	int	push;
	int	rot;

	push = 0;
	rot = 0;
	mid = middle_5(b->top);
	while (n--)
	{
		if (b->top->val >= mid)
		{
			pop_push(b, a, 'A');
			push++;
		}
		else
		{
			rotate(b, 'B');
			rot++;
		}
		if (push == 3)
			break ;
	}
	while (rot--)
		rotate_backward(b, 'B');
}

void	sort_five_handler(t_stack *a, t_stack *b, int flag, int n)
{
	print_string("fives.c, func:sort_five_handler");
	if (flag == 'A')
		sort_five_handler_a(a, b, n);
	else
		sort_five_handler_b(a, b, n);
	three_handler_a(a, 3);
	two_handler(a, b, 'B');
}

void	five_handler(t_stack *a, t_stack *b)
{
	print_string("fives.c, func: five_handler");
	int	pb;
	int	mid;

	pb = 0;
	mid = middle_5(a->top);
	while (1)
	{
		if (a->top->val < mid)
		{
			pop_push(a, b, 'B');
			pb++;
		}
		else
			rotate(a, 'A');
		if (pb == 2)
			break ;
	}
	three_handler_a(a, 3);
	two_handler(a, b, 'B');
}
