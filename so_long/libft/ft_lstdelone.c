/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:13:30 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/24 21:10:38 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{	
	t_list	*ptr;

	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	ptr = lst;
	lst = lst->next;
	free(ptr);
	ptr = NULL;
}

/*
void	del(void *content)
{
	free(content);
	content = NULL;
}
#include <stdio.h>
#include <string.h>
int	main(void)
{
	t_list	*ptr;

	ptr = ft_lstnew("Initial");
	printf("%d\n", ft_lstsize(ptr));
//	ft_lstdelone(ptr, del);
//	printf("%d\n", ft_lstsize(ptr));

	ft_lstadd_front(&ptr, ft_lstnew("8nd"));
	ft_lstadd_front(&ptr, ft_lstnew("7nd"));
	ft_lstadd_front(&ptr, ft_lstnew("6nd"));
	ft_lstadd_front(&ptr, ft_lstnew("5nd"));
	ft_lstadd_front(&ptr, ft_lstnew("4nd"));
	ft_lstadd_front(&ptr, ft_lstnew("3nd"));
	ft_lstadd_front(&ptr, ft_lstnew("2nd"));
	ft_lstadd_front(&ptr, ft_lstnew("1st"));

//	printf("%d\n", ft_lstsize(ptr));

	ft_lstdelone(ft_lstlast(ptr), del);
	printf("%d\n", ft_lstsize(ptr));

	t_list * l =  ft_lstnew(malloc(1));
	ft_lstdelone(l, free);
	printf("%p\n", l->next);
	l = 0;

	return (0);
}
*/
