/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:46:07 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/17 20:27:52 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *lst)
{
	int	temp;
	
	if (lst != NULL && lst->next != NULL)
	{
		temp = lst->next->val;
		lst->next->val = lst->val;
		lst->val = temp;
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
int	pop_push(t_stack *dst, t_stack *src)
{
	t_stack	*temp;
	if (src != NULL)
	{
		temp = src;
		src = src->next;
		temp->next = dst;
		dst = temp;
		free(temp);
		temp = NULL;
		return (1);
	}
	return (0);
}

void	pa(t_stack *a, t_stack *b)
{
	if (pop_push(a, b) == 1)
		write(1, "pa\n", 3);
}

void	pb(t_stack *b, t_stack *a)
{
	if (pop_push(b, a) == 1)
		write(1, "pb\n", 3);
}

t_stack	*lst_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	rotate_forward(t_stack *lst)
{
	t_stack	*tail;
	t_stack	*head;
	t_stack	*temp;
	
	if (lst != NULL && lst->next != NULL)
	{	
		head = lst->next;
		temp = lst;
		temp->next = NULL;
		temp->prev = lst_last(lst);
		
		tail = temp->prev;
	   	tail->next = temp;
		lst = head;
		return (1);
	}
	return (0);
}

void	ra(t_stack *a)
{
	if (rotate_forward(a) == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (rotate_forward(b) == 1)
		write(1, "rb\n", 3);
}


