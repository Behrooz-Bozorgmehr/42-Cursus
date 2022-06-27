/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:31:08 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/27 20:21:38 by bbozorgm         ###   ########.fr       */
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
}

int	words_count(char const *s, char c)
{
	int		counter;
	size_t	i;
	int		flag;

	counter = 0;
	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 0;
		else if (s[i] != c && flag == 0)
		{
			flag = 1;
			counter++;
		}
		i++;
	}
	return (counter);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
 	char	**ptr;
	t_stack	*a;
	t_stack	*b;

	i = 1;
	j = 0;
	ptr = NULL;
	a = NULL;
	b = NULL;
	if(argc > 1)
	{
		while (i < argc)
		{
			ptr = ft_split(argv[argc - i], ' ');
			while(ptr [j] != NULL)
				j++;
			a = init_step_1(a, ptr, j);
			free(ptr);
			ptr = NULL;	
			j = 0;
			i++;
		}
		print(a, b);

		/*
		t_stack	*a;
		t_stack	*b;
		
		a = init(size, argv);
		b = NULL;
//		print(a, b);
		sort(a, b);
		free_list(a);
		*/
	}
	return (0);
}
