
#include "push_swap.h"

int	atoi_func(char *str)	
{
	long long	conv;
	int			sign;

	conv = 0;
	sign = 1;
	while ((*str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
	}
	if (*str)
	{
		while (*str)
		{
			conv = conv * 10 + (*str - '0');
			str++;
		}
		conv *= sign;
		if (conv <= MAX_INT && conv >= MIN_INT)
			return (conv);
	}
	print_error();
	return (0);
}

// define neighbors of a node
void	set_connections(t_stack **stack, t_node **node, t_node **temp)
{
	if (*node == NULL)
	{
		*node = *temp;
		(*stack)->top = *node;
	}
	else
	{
		(*node)->next = *temp;
		(*temp)->prev = *node;
		*node = (*node)->next;
	}
}

// set values to a node and define its neighbors
int	set_node(t_stack **stack, t_node **node, char *str)
{
	int		i;
	char	**args;
	t_node	*temp;

	args = ft_split(str, ' ');
	if (*args == 0 )
		return (0);
	i = 0;
	while (args[i] != NULL)
	{	
		temp = init_node();
		if (temp == NULL || is_number(args[i]) == 0)
			print_error();
		temp->val = atoi_func(args[i]);
		set_connections(stack, node, &temp);
		(*stack)->size++;
		free(args[i]);
		args[i] = NULL;
		i++;
	}
	free(args);
	args = NULL;
	return (1);
}

// set values to stack layers and stay in top layer
void	fill_stack(t_stack *stack, char *argv[], int size)
{
	int		i;
	int		retval;
	t_node	*node;

	i = 1;
	node = NULL;
	while (i < size)
	{
		retval = set_node(&stack, &node, argv[i]);
		if (retval == 0)
			print_error();
		i++;
	}
	if (node->next == NULL)
		stack->bot = node;
	while (node->prev != NULL)
		node = node->prev;
}


