/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:08 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/07/04 19:45:37 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../Rank1/libft/libft.h"
t_stack	*init_step_1(t_stack *list, char *arg[], int size)
{
	int	i;
	int	value;

	i = size - 1;
	value = 0;
	if (is_string(arg, size) == 0)
	{
		if (list == NULL)
		{
			value = ft_atoi(arg[i]);
			list = lst_new(value);
			i--;
		}
		while (i >= 0)
		{
			value = ft_atoi(arg[i]);
			push(&list, lst_new(value));
			i--;
		}
		return (list);
	}
	return (NULL);
}
/*
t_stack	*init(int size, char *arg[])
{
	t_stack	*list;

	list = NULL;
	if (size > 0)
		list = init_step_1(list, arg, size);
	if (doublicated(list, size) == 0)
		return (list);
	else
	{
		write(STDERR, "Error\n", 6);
		free_list(list);
		return (NULL);
	}
}*/
t_stack	*init(int size, char *arg[])
{
	int		i;
	int		j;
 	char	**ptr;
	t_stack	*list;

	i = 1;
	j = 0;
	ptr = NULL;
	list = NULL;
	if(size > 1)
	{
		while (i < size)
		{
			ptr = ft_split(arg[size - i], ' ');
			while(ptr [j] != NULL)
				j++;
			list = init_step_1(list, ptr, j);
			free(ptr);
			ptr = NULL;	
			j = 0;
			i++;
			if (list == NULL)
				break ;
		}
	}
	if (doublicated(list) == 0)
		return (list);
	else
	{
		write(STDERR, "Error\n", 6);
		free_list(list);
		return (NULL);
	}
}
