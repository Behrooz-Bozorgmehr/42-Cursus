/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:43:30 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/21 10:19:38 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_print *tab)
{
	char	c;

	c = va_arg(tab->args, int);
	if (tab->wdt && !tab->dash)
		ft_right_cs(tab, 1, NULL);
	write(1, &c, 1);
	if (tab->wdt && tab->dash)
		ft_left_cs(tab, 1);
	ft_update_tab(tab, 1);
}

void	ft_print_str(t_print *tab)
{
	char	*str;
	int		len;

	str = va_arg(tab->args, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (len > tab->precision && tab->point > 0)
		len = tab->precision;
	if (len < tab->wdt && !tab->dash)
		ft_right_cs(tab, len, str);
	write(FD, str, len);
	if (len < tab->wdt && tab->dash)
		ft_left_cs(tab, len);
	ft_update_tab(tab, len);
}

void	ft_print_ptr(t_print *tab, char *ptr)
{
	int		len;
	char	spec;

	len = ft_strlen(ptr);
	spec = tab->spec;
	if (spec == 'p')
		len += 2;
	if (len <= tab->precision)
		ft_precision(tab, len, ptr);
	if ((len < tab->wdt) && !tab->dash)
		ft_right_cs(tab, len, ptr);
	ft_write_condition(tab, ptr, len);
	if (len < tab->wdt && tab->dash)
		ft_left_cs(tab, len);
	ft_update_tab(tab, len);
	ft_free(ptr);
}

char	*ft_free(char *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
	return (ptr);
}
