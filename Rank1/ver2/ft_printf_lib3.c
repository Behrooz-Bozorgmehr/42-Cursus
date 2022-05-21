/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:58:29 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/21 10:19:33 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print	*ft_init(t_print *tab)
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

int	ft_right_cs(t_print *tab, int i, char *ptr)
{
	int		len;
	char	padding;

	padding = ' ';
	len = tab->wdt - i;
	if (tab->is_zero)
	{
		if (*ptr < '0')
			write(FD, "-", 1);
		padding = '0';
	}
	while (len-- > 0)
		tab->totlen += write (FD, &padding, 1);
	return (0);
}

int	ft_left_cs(t_print *tab, int i)
{
	int		len;
	char	padding;

	padding = ' ';
	len = tab->wdt - i;
	while (len-- > 0)
		tab->totlen += write (FD, &padding, 1);
	return (0);
}

int	ft_precision(t_print *tab, int len, char *ptr)
{
	int		i;
	char	*pre;

	if (*ptr < '0')
	{
		write(FD, "-", 1);
		len--;
	}
	i = tab->precision - len;
	pre = (char *) malloc(sizeof(char) * (i + 1));
	if (pre != NULL)
	{
		pre[i] = '\0';
		while (--i >= 0)
			pre[i] = '0';
	}
	tab->totlen += write(FD, pre, ft_strlen(pre));
	ft_free(pre);
	return (0);
}
