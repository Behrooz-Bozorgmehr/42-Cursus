/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 18:47:45 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/07/05 19:15:44 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	if (rotate_forward(a) == 1)
		write(STDOUT, "ra\n", 3);
}

void	rb(t_stack **b)
{
	if (rotate_forward(b) == 1)
		write(STDOUT, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	if (rotate_forward(a) == 1)
		write(STDOUT, "ra\n", 3);
	if (rotate_forward(b) == 1)
		write(STDOUT, "rb\n", 3);
}

void	rra(t_stack **a)
{
	if (rotate_backward(a) == 1)
		write(STDOUT, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	if (rotate_backward(b) == 1)
		write(STDOUT, "rrb\n", 4);
}
