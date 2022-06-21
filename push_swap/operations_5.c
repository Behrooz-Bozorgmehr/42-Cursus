/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:57:59 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/21 20:55:25 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(t_stack **a, t_stack **b)
{
	if (rotate_backward(a) == 1)
		write(1, "rra\t", 4);
	if (rotate_backward(b) == 1)
		write(1, "rrb\n", 4);
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

int	is_string(char *ptr)
{
	while (*ptr != '\0')
	{
		if (('0' > (*ptr) || (*ptr) > '9') && ((*ptr) != '-' || (*ptr) != '+') )
		{
			write(1, "ERROR\n", 6);
			return (1);
		}
		ptr++;
	}
	return (0);
}

int	doublicated(t_stack *lst, int size)
{
	int	i;
	int j;
	int	retval;
	int	*arr;

	arr = (int *) malloc(sizeof(int) * size);
	i = 0;
	j = 0;
	retval = 0;
	while (lst != NULL)
	{
		arr[i] = lst->val;
		lst = lst->next;
		i++;
	}	
	i = 0;
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
	return (retval);
}
