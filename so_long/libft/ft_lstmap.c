/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:28:00 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/03/01 18:48:34 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{	
	t_list	*new_list;
	t_list	*fix_address;

	new_list = NULL;
	if (lst == NULL || f == NULL)
		return (NULL);
	fix_address = ft_lstnew(f(lst->content));
	if (fix_address != NULL)
	{
		new_list = fix_address;
		lst = lst->next;
		while (lst != NULL)
		{
			new_list->next = ft_lstnew(f(lst->content));
			if (new_list->next == NULL)
			{	
				ft_lstclear(&fix_address, del);
				return (NULL);
			}
			new_list = new_list->next;
			lst = lst->next;
		}
		new_list->next = NULL;
	}
	return (fix_address);
}

/*
void *		lstmap_f(void *content) {
	(void)content;
	return ("OK !");
}

#include <stdio.h>
#include <string.h>
int	main(void)
{

	t_list	*l = ft_lstnew(" 1 2 3 ");
	t_list	*ret;
	l->next = ft_lstnew("ss");
	l->next->next = ft_lstnew("-_-");
	ret = ft_lstmap(l, lstmap_f, NULL);
	
	printf("size l is: %d\n", ft_lstsize(l));
	printf("size ret is: %d\n", ft_lstsize(ret));
//	printf("size ret is: %d\n", ft_lstsize(ret));
	return (0);
}
*/
