/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:08 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/17 20:27:55 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *init(int size, char *arg[])
{
	t_stack	*list;
	int		i;
	int		value;
	
	i = 1;
	list = NULL;
	value = 0;
	if (size > 1)
	{
		value = ft_atoi(arg[i]);
		list = lstnew(value);
		while (i++ < size - 1 )
		{
			value = ft_atoi(arg[i]);
			push(&list, lstnew(value));
		}
	}
	return (list);
}


int	main(int argc, char *argv[])
{
	t_stack	*a;
	a = init(argc, argv);
	rotate_forward(a);
	while(a->next != NULL)
	{
		printf("val: %d\t next: %d\t prev : %d\n", a->val, a->next->val, a->prev->val);
		a = a->next;
	}
	printf("val: %d\t next: %p\t prev : %d\n", a->val, a->next, a->prev->val);



	return (0);
}
