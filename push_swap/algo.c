/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:01:30 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/19 19:01:17 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	check_order(t_stack *lst)
{
	int	sorted;
	
	sorted = 1;
	while (lst->next != NULL)
	{
		if (lst->val < lst->next->val)
			sorted = 1;
		else
		{
			sorted = 0;
			return (sorted);
		}
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
			sb(b);
	}
}

void	print(t_stack *a, t_stack *b)
{
	printf("\n a-stack %p\n", a);
	if (a != NULL)
	{	
		while(a	->next != NULL)
		{
			printf("a-val: %d\t a-next: %d\n", a->val, a->next->val);
			a = a->next;
		}
		printf("a-val: %d\t a-next: %p\n ", a->val, a->next);
	}
	
	printf("\n b_stack  %p\n", b);
	if (b != NULL)
	{
		while(b->next != NULL)
		{
			printf("b-val: %d\t b-next: %d\n ", b->val, b->next->val);
			b = b->next;
		}
		printf("b-val: %d\t b-next: %p\n", b->val, b->next);
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
		else if ((head->val < head->next->val && ((*b) == NULL ||  (*a)->val < (*b)->val) ) || sorted == 0)
		{
			write(1, "pb\n", 3);
			if (pop_push(b, a) == 1)
				b_algo(*b);
		}
		sorted = check_order(*a); 
		if ((sorted && (*b) != NULL) && (*a)->val < (*b)->val)
		{
			write(1, "pb\n", 3);
			if(pop_push(b, a) == 1)
				b_algo(*b);	
		}
		else  if ((sorted && (*b) != NULL) && (*a)->val > (*b)->val)
		{
			write(1, "pa\n", 3);
			pop_push(a, b);
		}
		head = *a;
		tail = lst_last(*a);
//		print(*a, *b);
	}
}

void	sort(t_stack *a, t_stack *b)
{
	int	sorted;
	sorted = check_order(a);
   	if(sorted == 0)
		a_algo(&a, a, lst_last(a), &b);
	while (a->next != NULL)
	{
		printf("val: %d\t next: %d\t prev : %d\n", a->val, a->next->val, a->prev->val);
		a = a->next;
	}
	printf("val: %d\t next: %p\t prev : %d\n", a->val, a->next, a->prev->val);

}

