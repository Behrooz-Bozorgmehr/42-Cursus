#include "push_swap.h"

void    five_handler_b(t_stack *a, t_stack *b, int size)
{
    int max;
    
    while(size)
    {
        max = maximum(b->top, size);
        if (b->top->val == max)
        {
            pop_push(a, b,'A');
            if (a->top->next->val < max)
                swap(a, 'A');
        }
        else
            rotate(b, 'B');
        size--;
    }
}

void    upto_five_handler_a(t_stack *a, t_stack *b, int size)
{
    int mid;
    int push;
    int rot;

    mid = middle(a->top, size);
    push = 0;
    rot = 0;
    while(size)
    {
        if (a->top->val < mid)
        {
            pop_push(b, a,'B');
            push++;
        }
        else
        {
            rotate(a, 'A');
            rot++;
        }
        if (push == 2)
            break;
        size--;
    }
    while(rot--)
        rotate_backward(a, 'A');
}

void    upto_five_handler_b(t_stack *a, t_stack *b, int size)
{
    int mid;
    int push;
    int rot;

    mid = middle(b->top, size);
    push = 0;
    rot = 0;
    while(size)
    {
        if (b->top->val >= mid)
        {
            pop_push(a, b,'A');
            push++;
        }
        else
        {
            rotate(b, 'B');
            rot++;
        }
        if (push == 3)
            break;
        size--;
    }
    while (rot--)
        rotate_backward(b, 'B');
}

void	upto_five_handler(t_stack *a, t_stack *b, char flag, int size)
{
	if (flag == 'A')
        upto_five_handler_a(a, b, size);
    else if (flag == 'B')
        upto_five_handler_b(a, b, size);
        upto_three_handler(a, b, 'A', 3);
        upto_three_handler(a, b, 'B', 2);
}
        

int	end_stack_handler(t_stack *a, t_stack *b, char flag, int size)
{
	if (size < 4)
	{
		upto_three_handler(a, b, flag, size);
		return (1);
	}
	else if (size < 6)
	{
		upto_five_handler(a, b, flag, size);
		return (1);
	}
	else
		return (0);
}