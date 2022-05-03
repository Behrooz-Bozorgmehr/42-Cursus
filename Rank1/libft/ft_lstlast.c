/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:53:09 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/20 16:37:03 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	t_list	*ptr;

	ptr = ft_lstnew("Initial");
	ft_lstadd_front(&ptr, ft_lstnew("8nd"));
	ft_lstadd_front(&ptr, ft_lstnew("7nd"));
	ft_lstadd_front(&ptr, ft_lstnew("6nd"));
	ft_lstadd_front(&ptr, ft_lstnew("5nd"));
	ft_lstadd_front(&ptr, ft_lstnew("4nd"));
	ft_lstadd_front(&ptr, ft_lstnew("3nd"));
	ft_lstadd_front(&ptr, ft_lstnew("2nd"));
	ft_lstadd_front(&ptr, ft_lstnew("1st"));

	ptr = ft_lstlast(ptr);
	printf("%s\n", ptr->content);
	printf("%p\n", ptr->next);
	
	return (0);
}
*/
