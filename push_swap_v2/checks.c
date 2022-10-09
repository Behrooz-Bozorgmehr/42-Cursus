#include "push_swap.h"
/*
// this function does not cover multiple signs as error so ignore it
int	check_args_length(char *args)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (args[0] == '+' || args[0] == '-')
	{
		i++;
		len--;
	}
	while (args[i] == '0')
		i++;
	while (args[i++])
		len++;
	return (len);
}
*/
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

int	is_integer(char *args)
{
	if (is_number(args) == 0)
		return (0);
	else
		return (1);
}

void	check_duplicated(t_stack *a)
{
	int		current_value;
	t_node	*tmp;
	t_node	*top;

	top = a->top;
	while (top->next)
	{
		tmp = top->next;
		current_value = top->val;
		while (tmp)
		{
			if (tmp->val == current_value)
				print_error();
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
		top = top->next;
	}
	//while (top->prev)
	//	top = top->prev;
}

int	check_order(t_stack *stack)
{
	int	sorted;
	t_node	*top;

	sorted = 1;
	top = stack->top;
	while (top->next != NULL)
	{
		if (top->val < top->next->val)
			sorted = 1;
		else
		{
			sorted = 0;
			return (sorted);
		}
		top = top->next;
	}
	return (sorted);
}