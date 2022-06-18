/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:08 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/18 17:27:17 by bbozorgm         ###   ########.fr       */
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
	a = init(argc, argv);
	b = NULL;	

	while(a->next != NULL)
	{
		printf("val: %d\t next: %d\t prev : %d\n", a->val, a->next->val, a->prev->val);
		a = a->next;
	}
	printf("val: %d\t next: %p\t prev : %d\n", a->val, a->next, a->prev->val);
	a  = init(argc, argv);
	sort(a,b);	
	return (0);
}
