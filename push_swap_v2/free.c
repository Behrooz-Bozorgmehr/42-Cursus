
#include	"push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->top;
	while (node != NULL)
	{
		if (node->next != NULL)
			tmp = node->next;
		else
			tmp = NULL;
		free(node);
		node = NULL;
		if (tmp != NULL)
			node = tmp;
		else
			break ;
	}
	stack->size = 0;
	free(stack);
	stack = NULL;
}

void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}


