/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:01:30 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/18 17:27:29 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_order(t_stack *lst)
{
	int	sorted;
	
	sorted = 0;
	while (lst->next != NULL)
	{
		if (lst->val < lst->next->val)
			sorted = 1;
		else
			sorted = 0;
		lst = lst->next;
	}
	return (sorted);
}
void	b_algo(t_stack *b)
{
	int	size;
	
	size =  lst_size(b);
	if (size >= 2)
	{
		if (b->val < b->next->val)
			swap(b);
	}
}

void	print(t_stack *a, t_stack *b)
{
	printf("\n a_stack \n");
	if (a != NULL)
	{	
		while(a	->next != NULL)
		{
			printf("val: %d\t next: %d\t prev : %d\n", a->val, a->next->val, a->prev->val);
			a = a->next;
		}
		printf("val: %d\t next: %p\t prev : %d\n", a->val, a->next, a->prev->val);
	}
	printf("\n b_stack \n");
	if (b != NULL)
	{
		while(b->next != NULL)
		{
			printf("val: %d\t next: %d\t prev : %d\n", b->val, b->next->val, b->prev->val);
			b = b->next;
		}
		printf("val: %d\t next: %p\t prev : %d\n", b->val, b->next, b->prev->val);
	}
}

void	a_algo(t_stack **a, t_stack *head, t_stack *tail, t_stack **b)
{
	int	sorted;

	sorted = check_order(*a);
	while (sorted == 0 || lst_size(*b) != 0)
	{
		if (tail->val < head->val && tail->val < head->next->val)
			rra(a);
		else if (head->next->val < head->val && head->next->val > tail->val)
			sa(*a);
		else if (head->next->val < tail->val && head->val > tail->val)
			ra(a);
		else if (tail->val < head->val)
			rra(a);
		else if (head->next->val < head->val)
			sa(*a);
		else if (head->val < head->next->val)
			pb(*b, *a);
		sorted = check_order(*a); 
//		if (sorted && (*a)->val > (*b)->val)
//			pa(*a, *b);
		head = *a;
		tail = lst_last(*a);

		print(head, *b);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	if (check_order(a) == 0)
		a_algo(&a, a, lst_last(a), &b);
/*	while (a->next != NULL)
	{
		printf("val: %d\t next: %d\t prev : %d\n", b->val, b->next->val, b->prev->val);
		a = a->next;
	}
	printf("val: %d\t next: %p\t prev : %d\n", a->val, a->next, a->prev->val);
*/
}

