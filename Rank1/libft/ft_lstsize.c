/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:35:15 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/21 20:13:54 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
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

	printf("%d\n", ft_lstsize(ptr));
	
	return (0);
}
*/
