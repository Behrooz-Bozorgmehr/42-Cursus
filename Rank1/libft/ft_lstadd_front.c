/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:19:41 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/20 16:01:21 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	t_list	*list;
	t_list	*last;
	last = ft_lstnew("last");
	list = ft_lstnew("first");
	list->next = last;

	t_list	*new;
	new = ft_lstnew("new");

	printf("%s\n", list->content);
	printf("%s\n\n\n", list->next->content);
	ft_lstadd_front(&list, new);

	printf("%s\n", list->content);
	printf("%s\n", list->next->content);
	printf("%s\n", list->next->next->content);
	
	return (0);
}
*/	
