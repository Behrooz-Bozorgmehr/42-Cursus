#include "push_swap.h"

void	init_ops(t_operation  *op)
{
	op->ra = 0;
	op->rb = 0;
	op->pa = 0;
	op->pb = 0;
//	op->pvt_a = 0;
//	op->pvt_b = 0;
}

t_node	*init_node()
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->val = 0;
	node->pos = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

t_stack	*init_stack()
{
	t_stack	*ptr;

	ptr = (t_stack *)malloc(sizeof(t_stack));
	if (ptr == NULL)
		return (NULL);
	ptr->size = 0;
	ptr->top = NULL;
	ptr->bot = NULL;
	return (ptr);
}

void 	init_pivots(t_stack *stack, t_operation *op, int n)
{
	int min;
	min = minimum(stack->top, n);
	op->pvt_a = (min + maximum(stack->top, n)) / 2;
	op->pvt_b = (min + (op->pvt_a)) / 2;
}
