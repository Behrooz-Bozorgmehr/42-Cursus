/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:57:59 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/07/05 20:32:39 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	if (rotate_backward(a) == 1)
		write(STDOUT, "rra\n", 4);
	if (rotate_backward(b) == 1)
		write(STDOUT, "rrb\n", 4);
}

void	free_list(t_stack *lst)
{
	t_stack	*temp;

	while (lst != NULL)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
		temp = NULL;
	}
}

int	is_string(char **arg, int size)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = arg[i];
	while (i < size)
	{
		while (*ptr != '\0')
		{
			if ((*ptr < '0' || *ptr > '9') && (*ptr != '-' && *ptr != '+'))
				return (1);
			if ((*ptr == '-' || *ptr == '+') && *(ptr + 1) != '\0'
				&& (*(ptr + 1) < '0' || *(ptr + 1) > '9'))
				return (1);
			if ((*ptr > '0' && *ptr < '9') && *(ptr + 1) != '\0'
				&& (*(ptr + 1) < '0' || *(ptr + 1) > '9'))
				return (1);
			ptr++;
		}
		i++;
		ptr = arg[i];
	}
	return (0);
}

int	is_doublicated(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (i != j && arr[i] == arr[j])
			{
				free (arr);
				arr = NULL;
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int	doublicated(t_stack *lst)
{
	int	i;
	int	*arr;
	int size;
   
	size = lst_size(lst);
	if (lst != NULL)
		arr = (int *) malloc(sizeof(int) * size);
	else
		return (1);
	i = 0;
	while (lst != NULL)
	{
		arr[i++] = lst->val;
		lst = lst->next;
	}
	return (is_doublicated(arr, size));
}
