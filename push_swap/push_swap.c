/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:08 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/07/09 17:01:08 by bbozorgm         ###   ########.fr       */
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
			ft_bzero(ptr, j);
			free(ptr);
			ptr = NULL;	
			j = 0;
			i++;
			if (list == NULL)
				break ;
		}
	}
	if (doublicated(list) == 0)
	{
		set_position(list, define_position(list));
		return (list);
	}
	else
	{
		write(STDERR, "Error\n", 6);
		free_list(list);
		return (NULL);
	}
}

int	*define_position(t_stack *lst)
{
	int i;
	int j;
	int	*ptr;
	int	size = lst_size(lst);

	if (lst != NULL)
	{
		ptr = (int *)malloc (sizeof(int) * size);	
		if (ptr != NULL)
		{
			i = 0;
			while (i < size)
			{
				ptr[i++] = lst->val;
				lst = lst->next;
			}
			quick_sort(ptr, 0, size - 1);		
			return (ptr);
		}
	}
	return (0);
}

void	set_position(t_stack *lst, int ptr[])
{
	int	i;
	int	size;

	size = lst_size(lst);

	while (lst != NULL)
	{
		i = -1;
		while (++i < size)
		{
			if (lst->val == ptr[i])
			{
				lst->pos = i;
				break;
			}
		}
		lst = lst->next;
	}
//	while(--size > 0)
//		ptr[size] = 0;
	free (ptr);
	ptr = NULL;

}

void	quick_sort(int arg[], int start, int end)
{
	int piv_ind;

	if (start < end)
	{
		piv_ind = partition(arg, start, end);
		quick_sort(arg, start, piv_ind - 1);
		quick_sort(arg, piv_ind + 1, end);
	}
}	

int	partition(int arg[], int start, int end)
{
	int	pivot;
	int	i;
	int j;
	int	temp;

	i = start - 1;
	j = start;
	pivot = arg[end];
	while (j < end - 1)
	{
		if (arg[j] < pivot)
		{	
			i++;
			if (i != j)
			{	temp = arg[i];
				arg[i] = arg[j];
				arg[j] = temp;
				j = i;
			}
		}
		j++;
	}
	i++;
	temp = arg[i];
	arg[i] = pivot;
	arg[end] = temp;
	return (i);
}





