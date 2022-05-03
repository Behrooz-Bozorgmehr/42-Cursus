/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:02:30 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/24 20:51:25 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	t_list * l =  NULL;// t_list * l2 =  NULL;
	t_list *k = ft_lstnew((void *) 1);
	printf("%s \n", k->content);
//  	ft_lstadd_back(&l, k);
	printf("%s \n", l->content);
/	ft_lstadd_back(&l, ft_lstnew((void*)2));
	ft_lstadd_back(&l2, ft_lstnew((void*)3));
	ft_lstadd_back(&l2, ft_lstnew((void*)4));
//	ft_lstadd_back(&l, l2);
	printf("%s  : %s  \n", l->content, (void*)1);
	// 7 / check(l->next->content == (void*)2);
	// 8 / check(l->next->next->content == (void*)3);
	// 9 / check(l->next->next->next->content == (void*)4);
	// 10 / check(l->next->next->next->next == 0);

	ft_lstadd_back(&ptr, new);
//	ptr = ft_lstlast(ptr);
	printf("%s\n", ptr->content);

	return (0);
}
*/
