/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:13:35 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/07/05 20:32:20 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *lst)
{
	int	temp;
	if (lst != NULL && (lst)->next != NULL)
	{
		temp = (lst)->val;
		(lst)->val = (lst)->next->val;
		(lst)->next->val = temp;	
		return (1);
	}
	return (0);
}

int	pop_push(t_stack **dst, t_stack **src)
{
	t_stack	*head;
	int		value;

	if (src != NULL)
	{
		head = *src;
		value = (*src)->val;
		*src = (*src)->next;
		if ((*src) != NULL)
			(*src)->prev = lst_last(*src);
		if (*dst != NULL)
			lst_add_front(dst, lst_new(value));
		else
			*dst = lst_new(value);
		free(head);
		head = NULL;
		return (1);
	}
	return (0);
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
