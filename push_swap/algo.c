/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 15:01:30 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/07/09 16:18:53 by bbozorgm         ###   ########.fr       */
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

	size = lst_size(b);
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
		while (a->next != NULL)
		{
			printf("a-val: %d\t a-pos: %d\t a-next: %d a-prv: %d\n", a->val, a->pos, a->next->val, a->prev->val);
			a = a->next;
		}
		printf("a-val: %d\t a-pos: %d\t a-next: %p\n ", a->val, a->pos,  a->next);
	}
	printf("\n b_stack  %p\n", b);
	if (b != NULL)
	{
		while (b->next != NULL)
		{
			printf("b-val: %d\t b-pos: %d\t b-next: %d\n ", b->val, b->pos,  b->next->val);
			b = b->next;
		}
		printf("b-val: %d\t b-pos: %d\t b-next: %p\n", b->val, b->pos, b->next);
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
		else if ((head->val < head->next->val && ((*b) == NULL
					|| (*a)->val < (*b)->val)) || sorted == 0)
			pb(b, a);
		sorted = check_order(*a);
		if ((sorted && (*b) != NULL) && (*a)->val < (*b)->val)
			pb(b, a);
		else if ((sorted && (*b) != NULL) && (*a)->val > (*b)->val)
			pa(a, b);
		head = *a;
		tail = lst_last(*a);
	}
}

void	algo_3(t_stack **a)
{
	int	val;
	int	n_val;
	int	p_val;

	val = (*a)->val;
	n_val = (*a)->next->val;
	p_val = (*a)->prev->val;
	if (val < p_val && n_val >p_val)
	{
		rra(a);
		sa(*a);
	}
	else if (val > n_val && p_val > val)
		sa(*a);
	else if (val < n_val && val > p_val)
	   rra(a);
	else if (val > n_val && n_val > p_val)
	{
		sa(*a);
		rra(a);
	}
	else if (val > n_val && n_val < p_val)
	{
		rra(a);
		rra(a);
	}
}	

void	algo_5(t_stack **a, t_stack **b)
{
	int	val;
	int	n_val;
	int	p_val;
	int size;

	size = lst_size(*a);
	while (check_order(*a) == 0 || lst_size(*a) != size)
	{
		while (lst_size(*a) > 3 && check_order(*a) == 0)
		{
			val = (*a)->val;
			n_val = (*a)->next->val;
			p_val = (*a)->prev->val;
			if (val < n_val && val < p_val)
				pb(b, a);
			else if (val > n_val)
				sa(*a);
			else if (p_val < val)
				rra(a);
		}
		if (lst_size(*a) == 3)
			algo_3(a);
		if (lst_size(*b) == 2 && check_order(*b) == 1) // should be inversly ordered
			sb(*b);
		else if (*b != NULL)
			pa(a, b);
	}
}


int	maximum(t_stack *lst)
{
	int	max;
	
	max = lst->val;
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
		if (lst->val > max)
			max = lst->val;
	}
	return (max);
}
int	minimum(t_stack *lst)
{
	int	min;
	
	min = lst->val;
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
		if (lst->val < min)
			min = lst->val;
	}
	return (min);
}

int	position(t_stack *lst, int (*func)(t_stack *))
{
	int	pos;
	int	min;

	pos = 0;
	min = func(lst);
	while (lst != NULL)
	{
		pos++;
		if (lst->val == min)
			return (pos);
		lst = lst->next;
	}
	return (pos);
}

void	algo_b(t_stack **b, t_stack **a)
{
	int	val;
	int n_val;
	int p_val;
	while(lst_size(*b) > 0)
	{
		val = (*a)->val;
		n_val = (*a)->next->val;
		p_val = (*a)->prev->val;
		int	pos = position(*a, minimum);
		int max = maximum(*a);
		int size = lst_size(*a);
		if (val == max)
			pa(a, b);
		else if (pos > size / 2 +1)
			rrb(b);
		else if (pos <= size / 2 + 1)
			rb(b);
	}
}

void	algo_big(t_stack **a, t_stack **b)
{
	int	val;
	int	n_val;
	int	p_val;
	int size;
	
	size = lst_size(*a);
	while (check_order(*a) == 0)
	{
		while (lst_size(*a) > 3 && check_order(*a) == 0)
		{
		val = (*a)->val;
			n_val = (*a)->next->val;
			p_val = (*a)->prev->val;
			int	pos = position(*a, minimum);
			int min = minimum(*a);
			int size = lst_size(*a);
			if (val == min)// || (val < n_val && val < p_val))
				pb(b, a);
		//	else if ((val < n_val && val > p_val) || (pos > size / 2 +1))
		//		rra(a);
			
		//	else if (val > n_val && n_val < p_val)
		//		sa(*a);
		//	else if (val > n_val && n_val > p_val)
	//			rra(a);
			else if (pos > lst_size(*a) / 2 + 1)
				rra(a);
			else if (pos <= size / 2 + 1)
				ra(a);
			
	
		}
		if (lst_size(*a) == 3)
			algo_3(a);
	}
//	algo_b(b,a);
	while (*b != NULL)
		pa(a, b);

	
		
}

// function is called if & only if stack is not sorted
void	algo(t_stack **a, t_stack **b)
{
	int size;

	size = lst_size(*a);
	if (size == 2)
		sa(*a);
	else if (size ==  3)
		algo_3(a);
//	else if (size <= 5)
//		algo_5(a, b);
	else //if(size > 5)
		algo_big(a, b);
}

void	sort(t_stack **a, t_stack **b)
{
	int	sorted;
	if (a != NULL)
	{
		sorted = check_order(*a);
		if (sorted == 0)
	//		a_algo(a, *a, lst_last(*a), b);
			algo(a, b);
	}
}
