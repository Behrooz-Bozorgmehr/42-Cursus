/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:43:30 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/21 04:07:27 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_print_char(t_print *tab)
{
    char c;

    c = va_arg(tab->args, int);
    if (tab->wdt && !tab->dash)
		ft_right_cs(tab, 1, NULL);
    write(1, &c, 1);
    if (tab->wdt && tab->dash)
		ft_left_cs(tab, 1);
	ft_update_tab(tab,1);
}

void	ft_print_str(t_print *tab)
{
	char	*str;
  	int		len;

	str = va_arg(tab->args, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (len > tab->precision)
		str[tab->precision] = '\0';
	len = ft_strlen(str);
	if (len < tab->wdt && !tab->dash)
        ft_right_cs(tab, len, str);
    write(FD, str, len);
    if (len < tab->wdt && tab->dash)
        ft_left_cs(tab, len);
	ft_update_tab(tab, len);

}
void	ft_set_ptr(t_print *tab, char *ptr)
{
	int i;

	i = 0;
	if(ptr[i] > 0)
		ptr[i++] = '-';
	ptr[tab->precision -1] = '1';
	while (i < tab->precision -1)
		ptr[i++] = '0';
	ptr[i] = '\0';
	write(FD, ptr, i);
	ft_update_tab(tab, i);
	ft_free(ptr);
}
void	ft_print_ptr(t_print *tab, char *ptr)
{
	int	len;
	char	spec;
	len = ft_strlen(ptr);
	spec = tab->spec;

	if (spec == 'p')
		len += 2;	
	if (len <= tab->precision)
		ft_precision(tab, len, ptr);
/*	else if (tab->precision > len)
	{	
		ft_set_ptr(tab, ptr);
		return ;
	}
*/	if ((len < tab->wdt) && !tab->dash) 
	    ft_right_cs(tab, len, ptr);
	if (tab->spec == 'p')
		write(FD, "0x", 2);
	else if ((spec == 'd' || spec == 'i') && tab->sign > 0 && (*ptr >= '0'))
		tab->totlen += write(FD, "+", 1);
	else if ((spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x' || spec == 'X') && tab->sp > 0 && (*ptr >= '0'))
		tab->totlen += 	write(FD, " ", 1);
	if (tab->htag > 0 && (spec == 'x' || spec == 'X') && (*ptr > '0') )
	{
		tab->totlen += write(FD, "0",1);
		tab->totlen += write(FD, &tab->spec, 1);
	}
	if (*ptr < '0' && ((len < tab->wdt && !tab->dash) || (len <= tab->precision)))
		write(FD, ptr + 1, ft_strlen(ptr+1));
	else //if (*ptr >= '0' && (len <= tab->precision || (len < tab->wdt &&  !tab->dash)))
		write(FD, ptr , ft_strlen(ptr));
//	else
//		write(FD, "1", 1);
	if (len < tab->wdt && tab->dash)
	    ft_left_cs(tab, len);
	ft_update_tab(tab, len);
	ft_free(ptr);
}
/*
long	ft_ptr_value(char	*ptr)
{
	size_t	i;
	long	retval;
	int		sign;

	i = 0;
	retval = 0;
	sign = 1;
	if (ptr[i] == '-')
	{
		i++;i
		sign = -1;
	}
	while (ft_isdigit(ptr[i]))
		retval = (int)ptr[i++] + retval * 10;
	if (i == ft_strlen(ptr))
	{
		retval = sign * retval;
		return (retval);
	}
	return (0);
}
*/
char	*ft_free(char *ptr)
{
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
	return (ptr);
}
