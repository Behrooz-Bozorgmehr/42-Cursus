/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:46:07 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/18 17:27:26 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *lst)
{
//	t_stack *temp;
	int temp;
	if (lst != NULL && (lst)->next != NULL)
	{
/*		temp = *lst;
		*lst = (*lst)->next;
		temp->next = (*lst)->next;
		(*lst)->next = temp;
		temp->next->prev = temp;
		(*lst)->prev = temp->prev;
		temp->prev = *lst;
*/
		temp = (lst)->val;
		(lst)->val = (lst)->next->val;
		(lst)->next->val = temp;
		return (1);
	}
	return (0);
}
	
void	sa(t_stack *a)
{
	if (swap(a) == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (swap(b) == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (swap(a) == 1)
		write(1, "sa\t", 3);
	if (swap(b) == 1)
		write(1, "sb\n", 3);
}
/*
void	lstadd_front(t_stack **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
*/
int	pop_push(t_stack **dst, t_stack **src)
{
	t_stack	*temp;
	if (src != NULL)
	{
		printf("pop_push : src-val: %d\t src-next: %d\t src-prev: %d\n", (*src)->val, (*src)->next->val, (*src)->prev->val);
		temp = *src;
		*src = (*src)->next;
		(*src)->prev = temp->prev;
		temp->next = *dst;
		temp->prev = (*dst)->prev;
		*dst = temp;
		free(temp);
		temp = NULL;
		return (1);
	}
	return (0);
}

void	pa(t_stack *a, t_stack *b)
{
	if (pop_push(&a, &b) == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	if (pop_push(&b, &a) == 1)
	{
		write(1, "pb\n", 3);
		b_algo(b);
	}
}

t_stack	*lst_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	rotate_forward(t_stack **lst)
{
	t_stack	*tail;

	if (*lst != NULL && (*lst)->next != NULL)
	{	
		tail = lst_last(*lst);
		tail->next = *lst;
		tail = tail->next;
		*lst = (*lst)->next;
		tail->next = NULL;
		return (1);
	}
	return (0);
}


int	rotate_backward(t_stack **lst)
{
	t_stack	*tail;
	if (*lst != NULL && (*lst)->next != NULL)
	{	
		tail = lst_last(*lst);
		tail->next = *lst;
		tail->prev->next = NULL;
		*lst = tail;
		return (1);
	}
	return (0);
}

void	ra(t_stack **a)
{
	if (rotate_forward(a) == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (rotate_forward(b) == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if (rotate_forward(a) == 1)
		write(1, "ra\t", 3);
	if (rotate_forward(b) == 1)
		write(1, "rb\n", 3);
}

void	rra(t_stack **a)
{
	if (rotate_backward(a) == 1)
		write(1, "rra\n", 3);
}

void	rrb(t_stack **b)
{
	if (rotate_backward(b) == 1)
		write(1, "rrb\n", 3);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (rotate_backward(a) == 1)
		write(1, "rra\t", 4);
	if (rotate_backward(b) == 1)
		write(1, "rrb\n", 4);
}
