/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:21:33 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/07/05 20:32:18 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_new(int value)
{
	t_stack	*list;

	list = (t_stack *) malloc(sizeof(t_stack));
	if (list != NULL)
	{
		list->val = value;
		list->next = NULL;
		list->prev = NULL;
	}
	return (list);
}

int	lst_size(t_stack *lst)
{
	int	len;

	len = 1;
	if (lst == NULL)
		return (0);
	while (lst->next != NULL)
	{
		len++;
		lst = lst->next;
	}
	return (len);
}

void	lst_add_front(t_stack **lst, t_stack *new)
{
	new->next = *lst;
	*lst = new;
	(*lst)->prev = (*lst)->next->prev;
	(*lst)->next->prev = (*lst);
}

t_stack	*lst_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	push(t_stack **lst, t_stack *elm)
{
	elm->next = *lst;
	elm->next->prev = elm;
	*lst = elm;
	(*lst)->prev = lst_last(*lst);
}
