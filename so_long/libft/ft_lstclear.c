/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 19:12:13 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/20 16:10:15 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	while ((*lst)->next != NULL)
	{
		ptr = *lst;
		*lst = (*lst)->next;
		del(ptr->content);
		free(ptr);
		ptr = NULL;
	}
	del((*lst)->content);
	free(*lst);
	*lst = NULL;
}
