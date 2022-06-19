/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:08 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/19 19:01:06 by bbozorgm         ###   ########.fr       */
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
/*	char *ptr[] = {"25", "-25"};
	b = init(2, ptr);	
	printf("sorted : %d\n", check_order(a));
	print(a, b);
	printf("size a: %d\t size b: %d\n", lst_size(a), lst_size(b));

	pop_push(&a, &b);
	printf("size a: %d\t size b: %d\n", lst_size(a), lst_size(b));
	print(a, b);

	pop_push(&a, &b);
	printf("size a: %d\t size b: %d\n", lst_size(a), lst_size(b));
	print(a, b);

*/	
	sort(a,b);

/*

	while(a->next != NULL)
	{
		printf("val: %d\t next: %d\t prev : %d\n", a->val, a->next->val, a->prev->val);
		 a= a->next;
	}
	printf("val: %d\t next: %p\t prev : %d\n", a->val, a->next, a->prev->val);
	a  = init(argc, argv);
*/		return (0);
}
