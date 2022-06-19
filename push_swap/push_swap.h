/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:25:33 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/19 19:01:15 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define	TRUE 1;
#define FALSE 0;
typedef struct	s_stack
{
	int 			val;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		ft_atoi(const char *str);
void	push(t_stack **lst, t_stack *elm);
t_stack	*lst_new(int value);
t_stack	*init(int size, char *arg[]);
t_stack	*lst_last(t_stack *lst);
int		lst_size(t_stack *lst);
void	lst_add_front(t_stack **lst, t_stack *elm);
int		rotate_forward(t_stack **lst);
int		rotate_backward(t_stack **lst);
int		swap(t_stack *lst);
int		check_order(t_stack *lst);
void	b_algo(t_stack *b);
void	a_algo(t_stack **a, t_stack *head, t_stack *tail, t_stack **b);
int		pop_push(t_stack **dst, t_stack **src);
void	sort(t_stack *a, t_stack *b);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *dst, t_stack *src);
void	pb(t_stack *dst, t_stack *src);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	print(t_stack *a, t_stack *b);
#endif /* PUSH_SWAP_H */
