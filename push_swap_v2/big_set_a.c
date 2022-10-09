#include "push_swap.h"

/*
 * If the top of the stack a is bigger than the big_pivot,
 * then rotate the stack a and add 1 to var->ra.
 * Othwewise, push the top of the stack a to the stack b,
 * and add 1 to var->pb.
 * If the top of the stack b is bigger than the small_pivot,
 * then rotate the stack b, we also have to add 1 to rb, keeping track
 * of the operations been made.
 */

void	pop_from_a(t_stack *a, t_stack *b, t_operation *ops)
{
	if (a->top->val > ops->pvt_a)
	{
		rotate(a, 'A');
		ops->ra++;
	}
	else
	{
		pop_push(b, a, 'B');
		ops->pb++;
		if (b->top->val > ops->pvt_b)
		{
           	rotate(b, 'B');
			ops->rb++;
		}
	}
}

void	return2origin_aa(t_stack *a, t_stack *b, t_operation *ops, int *count)
{
	int	rot_back;
	int	rest;
   	rot_back = ops->rb;
	rest = ops->ra - rot_back;
   
	if ((*count) > 0)
	{
    	while (rot_back--)
			rotate_both_backward(a, b);
		while (rest--)
			rotate_backward(a, 'A');
            
	}
	else
    {
    	while (rot_back--)
			rotate_backward(b, 'B');
	}
    
}

void	return2origin_ba(t_stack *a, t_stack *b, t_operation *ops, int *count)
{
	int	rot_back;
	int	rest;

	rot_back = ops->ra;
	rest = ops->rb - rot_back;
  	if ((*count) > 0)
	{
		while (rot_back--)
			rotate_both_backward(a, b);
		while (rest--)
			rotate_backward(b, 'B');
	}
	else
	{
		rot_back = ops->rb;
		while (rot_back--)
			rotate_backward(b, 'B');
	}
    
}

/*ll
 * Select two pivots,
 * big_pivot = (min + max) / 2
 * small_pivot = (min + big_pivot) / 2
 * While there is size of stack a, do the push_rotate_a.
 * Call the function recursively.
 * a_to_b(number of ra times)(1)
 * b_to_a(number of rb times)(2)
 * b_to_a(number of pb - rb times)(3)
 * After counting ra and rb, we check if ra is bigger than
 * rb, if so, it means that ra left and so we have to repeat the process
 * as long as it left vals.
 */

void	moves_a2b(t_stack *a, t_stack *b, int size, int *count)
{
	t_operation	ops;

	if (end_stack_handler(a, b, 'A', size) == 1)
		return ;
	init_ops(&ops);
	init_pivots(a, &ops, size);
	while (size--)
		pop_from_a(a, b, &ops);
	if (ops.ra > ops.rb)
		return2origin_aa(a, b, &ops, count);
	else
		return2origin_ba(a, b, &ops, count);
	moves_a2b(a, b, ops.ra, count);
	moves_b2a(a, b, ops.rb, count);
	moves_b2a(a, b, (ops.pb - ops.rb), count);
    
}
