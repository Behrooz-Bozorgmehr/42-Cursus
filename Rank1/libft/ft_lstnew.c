/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:08:20 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/20 16:01:05 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = (t_list *) malloc(sizeof(t_list));
	if (list != NULL)
	{
		list->content = content;
		list->next = NULL;
	}
	return (list);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	t_list *ptr;

	char	*str = "THIS";
	ptr = ft_lstnew(str);

	printf("%s\n", ptr->content);
	printf("%p\n", ptr->next);
	return (0);
}
*/
