
#include "push_swap.h"

void	two_handler(t_stack *a, t_stack *b, int flag)
{
	print_string("under_three.c, func:two_handler");
	if (flag == 'A')
	{
		if (a->top->val > a->top->next->val)
			swap(a, 'A');
	}
	else
	{
		if (b->top->val < b->top->next->val)
			swap(b, 'B');
		pop_push(a, b, 'A');
		pop_push(a, b, 'A');
	}
}

void	under_three_handler(t_stack *a, t_stack *b, int flag, int n)
{
	print_string("under_three.c, func:under_three_handler");
	//write(1,"flag is:", 10);
	//write(1, &flag, 2);
		
	if (n == 3)
	{
		if (flag == 'A')
			three_handler_a(a, n);
		else
			three_handler_b(a, b, n);
	}
	else if (n == 2)
		two_handler(a, b, flag);
	else if (n == 1)
	{
		if (flag == 'B')
			pop_push(b, a, 'A');
	}
}
