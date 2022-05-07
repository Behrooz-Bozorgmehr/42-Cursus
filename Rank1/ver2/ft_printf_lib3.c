/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:58:29 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/07 14:38:03 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print *ft_init(t_print *tab)
{
	tab->spec = 0;
	tab->dash = 0;
	tab->sign = 0;
	tab->htag = 0;
	tab->is_zero = 0;
	tab->wdt = 0;
	tab->precision = 0;
	tab->sp = 0;
	tab->point = 0;
	tab->pcent = 0;
	tab->totlen = 0;
	return (tab);
}

void	ft_update_tab(t_print *tab, int i)
{
	i += tab->totlen;
	ft_init(tab);
	tab->totlen = i;
}
/*
int	ft_right_cs(t_print *tab, int i)
{

}

int	ft_left_cs(t_print *tab, int i)
{

}
*/
