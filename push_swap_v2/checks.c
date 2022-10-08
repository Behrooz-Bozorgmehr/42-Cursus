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

void	check_duplicated(t_node *a)
{
	int		current_value;
	t_node	*tmp;

	while (a->next)
	{
		tmp = a->next;
		current_value = a->val;
		while (tmp)
		{
			if (tmp->val == current_value)
				print_error();
			if (tmp->next)
				tmp = tmp->next;
			else
				break ;
		}
		a = a->next;
	}
	while (a->prev)
		a = a->prev;
}
