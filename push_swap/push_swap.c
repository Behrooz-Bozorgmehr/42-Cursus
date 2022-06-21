/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:08 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/21 20:40:29 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init(int size, char *arg[])
{
	t_stack	*list;
	int		i;
	int		value;

	i = size - 1;
	list = NULL;
	value = 0;
	if (size > 0)
	{
		value = ft_atoi(arg[i]);
		list = lst_new(value);
		while (i-- > 0)
		{
			value = ft_atoi(arg[i]);
			if (is_string(arg[i]) == 0)
				push(&list, lst_new(value));
			else
			{
				write(1, "Error11\n", 8);
				free_list(list);
				return (NULL);
			}
		}
	}
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
//	print (a, b);
//	sort(a, b);
	is_string("-102");

	return (0);
}
