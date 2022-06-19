/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:08 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/19 19:15:28 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init(int size, char *arg[])
{
	t_stack	*list;
	int		i;
	int		value;
	
	i = 0;
	list = NULL;
	value = 0;
	if (size > 0)
	{
		value = ft_atoi(arg[i]);
		list = lst_new(value);
		while (i++ < size - 1 )
		{
			value = ft_atoi(arg[i]);
			push(&list, lst_new(value));
		}
	}
	return (list);
}


int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	a = init(argc - 1, argv + 1);
	b = NULL;
	sort(a,b);

	return (0);
}
