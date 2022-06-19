/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:46:07 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/19 19:18:39 by bbozorgm         ###   ########.fr       */
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

void	lst_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
//	new->prev = (*lst)->prev;
//	(*lst)->prev = new;
	*lst = new;
	(*lst)->prev = (*lst)->next->prev;
	(*lst)->next->prev = (*lst);
//	new->prev =  NULL;

}

int	pop_push(t_stack **dst, t_stack **src)
{
	t_stack	*head;
	int value;

	if (src != NULL)
	{
		head = *src;
		value = (*src)->val;
		*src = (*src)->next;
		if ((*src) != NULL)
			(*src)->prev =  lst_last(*src);

		if (*dst != NULL)
		{
			lst_add_front(dst, lst_new(value));
		}
		else
			*dst = lst_new(value);	
					
		free(head);
		head = NULL;
		return (1);
	}
	return (0);
}
// source is "b" destination is "a"
void	pa(t_stack *a, t_stack *b)
{
	if (pop_push(&a, &b) == 1)
		write(1, "pa\n", 3);
}
// source is "a" destination is "b"
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
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (rotate_backward(b) == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	if (rotate_backward(a) == 1)
		write(1, "rra\t", 4);
	if (rotate_backward(b) == 1)
		write(1, "rrb\n", 4);
}
