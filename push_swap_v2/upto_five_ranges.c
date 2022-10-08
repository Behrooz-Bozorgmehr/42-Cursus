#include "push_swap.h"

void    five_handler_a(t_stack *a, t_stack *b, int size)
{
    int middle;
    int push;
    int rot;

    middle = fives_middle(a->top, size);
    push = 0;
    rot = 0;
    while(1)
    {
        if (a->top->val < middle)
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
    }
    //while (rot--)
    //    rotate_backward(a, 'A');
    under_three_handler(a, b, 'A', a->size);
    under_three_handler(a, b, 'B', b->size);
}

void    five_handler_b(t_stack *a, t_stack *b, int size)
{
    int middle;
    int push;
    int rot;

    middle = fives_middle(b->top, size);
    push = 0;
    rot = 0;
    while(1)
    {
        if (b->top->val >= middle)
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
    }
   // while (rot--)
     //   rotate_backward(b, 'B');
    under_three_handler(a, b, 'A', a->size);
    under_three_handler(a, b, 'B', b->size);
}

void	five_handler(t_stack *a, t_stack *b, char flag, int size)
{
	if (flag == 'A')
        five_handler_a(a, b, size);
    else if (flag == 'B')
        five_handler_b(a, b, size);
}