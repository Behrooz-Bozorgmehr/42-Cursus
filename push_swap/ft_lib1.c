/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:58:01 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/19 19:18:44 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_to_number(const char *str, int sign)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
		if (num == 214748364 && str[i] <= '7')
		{
			num = num * 10 + str[i] - '0';
			break ;
		}
		if (num == 214748364 && str[i] == '8' && sign == -1)
			return (-2147483648);
		if (num >= 214748364 && (str[i] >= '0' && str[i] <= '9'))
		{
			if (sign == -1)
				return (0);
			return (-1);
		}	
	}
	return (num * sign);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i] == '-');
		i++;
	}
	num = ft_to_number(str + i, sign);
	return (num);
}

void	push(t_stack **lst, t_stack *elm)
{
	elm->next = *lst;
	elm->next->prev = elm;
	*lst = elm;
	(*lst)->prev = lst_last(*lst);
}

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
