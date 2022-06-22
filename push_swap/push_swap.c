/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:08 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/22 19:52:55 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_step_1(t_stack *list, char *arg[], int size)
{
	int	i;
	int	value;

	i = size -1;
	value = 0;
	if (is_string(arg, size) == 0)
	{
		value = ft_atoi(arg[i]);
		list = lst_new(value);
		while (i-- > 0)
		{
			value = ft_atoi(arg[i]);
			push(&list, lst_new(value));
		}
		return (list);
	}
	return (NULL);
}

t_stack	*init(int size, char *arg[])
{
	t_stack	*list;

	list = NULL;
	if (size > 0)
		list = init_step_1(list, arg, size);
	if (doublicated(list, size) == 0)
		return (list);
	else
	{
		write(1, "Error\n", 6);
		free_list(list);
		return (NULL);
	}
}

int	main(int argc, char *argv[])

{
	t_stack	*a;
	t_stack	*b;

	a = init(argc - 1, argv + 1);
	b = NULL;
	print (a, b);
	sort(a, b);
	return (0);
}
