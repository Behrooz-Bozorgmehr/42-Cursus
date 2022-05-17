/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:43:30 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/17 21:44:18 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	ft_print_char(t_print *tab)
{
    char c;

    c = va_arg(tab->args, int);
    if (tab->wdt && !tab->dash)
		ft_right_cs(tab, 1);
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
    if (tab->wdt && !tab->dash)
        ft_right_cs(tab, len);
     write(FD, str, len);
    if (tab->wdt && tab->dash)
        ft_left_cs(tab, len);
	ft_update_tab(tab, len);

}

void	ft_print_ptr(t_print *tab, char *ptr)
{
	int	len;
	len = ft_strlen(ptr);
   	if (tab->spec == 'p')
		len += 2;
 // 	if (tab->wdt && !tab->dash)
//	    ft_right_cs(tab, len);
 	if ((tab->spec == 'd' || tab->spec == 'i') && tab->sign > 0 && (*ptr >= '0'))
		tab->totlen += write(FD, "+", 1);
	else if ((tab->spec == 'd' || tab->spec == 'i') && tab->sp > 0 && (*ptr >= '0'))
		tab->totlen += write(FD, " ", 1);
	if (tab->spec == 'p')
	   	write(FD, "0x", 2);
	if (tab->htag > 0 && (tab->spec == 'x' || tab->spec == 'X') && (*ptr > '0') )
	{
		tab->totlen += write(FD, "0",1);
		tab->totlen += write(FD, &tab->spec, 1);
	}
	write(FD, ptr, ft_strlen(ptr));
//	if (tab->wdt && tab->dash)
//	    ft_left_cs(tab, ft_strlen(ptr));
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
		i++;
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
