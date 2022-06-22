/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:46:07 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/22 20:10:50 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	if (swap(a) == 1)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	if (swap(b) == 1)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b)
{
	if (swap(a) == 1)
		write(1, "sa\t", 3);
	if (swap(b) == 1)
		write(1, "sb\n", 3);
}

// source is "b" destination is "a"
void	pa(t_stack **a, t_stack **b)
{
	if (pop_push(a, b) == 1)
		write(1, "pa\n", 3);
}

// source is "a" destination is "b"
void	pb(t_stack **b, t_stack **a)
{
	if (pop_push(b, a) == 1)
	{
		write(1, "pb\n", 3);
		b_algo(*b);
	}
}
