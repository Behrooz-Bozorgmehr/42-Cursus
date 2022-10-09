#include "push_swap.h"

void	two_handler(t_stack *a, t_stack *b, int flag)
{
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

void	upto_three_handler(t_stack *a, t_stack *b, char flag, int size)
{
	if (size == 3)
	{
		if (flag == 'A')
			three_handler_a(a, size);
		else
		{
            three_handler_b(a, b, size);
            pop_push(a, b, 'A');
            pop_push(a, b, 'A');
            pop_push(a, b, 'A');
        }
	}
	else if (size == 2)
		two_handler(a, b, flag);
	else if (size == 1)
	{
		if (flag == 'B')
			pop_push(a, b, 'A');
	}
}
/*
void	three_handler_a(t_stack *a)
{
	int	mid;
	int	bot;

	mid = a->top->next->val;
	bot = a->bot->val;
	if (a->top->val < bot && mid >bot)
	{
		rotate_backward(a, 'A');
		swap(a, 'A');
	}
	else if (a->top->val > mid && bot > a->top->val)
		swap(a, 'A');
	else if (a->top->val < mid && a->top->val> bot)
	   rotate_backward(a, 'A');
    else if (a->top->val > mid)
    {
        if (mid > bot)
            swap(a, 'A');
        else
            rotate_backward(a, 'A');
        rotate_backward(a, 'A');
    }
}	

void	three_handler_b(t_stack *b)
{
 	int	mid;
	int	bot;

	mid = b->top->next->val;
	bot = b->bot->val;
	if (b->top->val > bot && mid < bot)
	{
        rotate_backward(b, 'B');
        swap(b, 'B');
    }
	else if (b->top->val > mid && bot > b->top->val)
		rotate_backward(b, 'B');
	else if (b->top->val < mid && b->top->val > bot)
	    swap(b, 'B');
    else if (b->top->val < mid )
    {
        if (mid < bot)
            swap(b, 'B');
        else
            rotate_backward(b, 'B');
        rotate_backward(b, 'B');
    }
}	
*/