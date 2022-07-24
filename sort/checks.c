
#include "push_swap.h"


int	is_number(char	*s)
{
	int	i;

	i = 0;
	if (*s == 0)
		return (0);
	if (s[i] == '-' || s[i] == '+')
			i++;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	doublicated(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (i != j && arr[i] == arr[j])
			{
				free (arr);
				arr = NULL;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	is_doublicated(t_stack *stack)
{
	int	i;
	int	*arr;
	int size;
	t_node *fix;

	size = stack->size;
	fix = stack->top;
	if (stack->top != NULL)
		arr = (int *) malloc(sizeof(int) * size);
	else
		return (1);
	i = 0;
	while (stack->top != NULL)
	{
		arr[i++] = stack->top->val;
		stack->top = stack->top->next;
	}
	stack->top = fix;
	return (doublicated(arr, size));
}

t_stack	*do_checks(t_stack *stack, t_stack *b)
{
	t_node	*node;
	int		size;

	node = stack->top;
    size = stack->size;
	if (is_doublicated(stack) == 0)
	{
		set_position(node, define_position(node, size), size);
		return (stack);
	}
	else
	{
		free_all(stack, b);
		print_msg();
		return (NULL);
	}
}
