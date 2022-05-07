/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:43:30 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/07 20:23:54 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_print *tab)
{
    char c;

    c = va_arg(tab->args, int);
	ft_update_tab(tab, 1);
//    if (tab->wdt && !tab->dash)
//        ft_right_cs(tab, 0);
    write(1, &c, 1);
//    if (tab->wdt && tab->dash)
//        ft_left_cs(tab, 0);
}

void	ft_print_str(t_print *tab)
{
    char	*str;
	int		len;

    str = va_arg(tab->args, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	ft_update_tab(tab, len);
/*    if (tab->wdt && !tab->dash)
        ft_right_cs(tab, 0);
*/   write(FD, str, len);
/*    if (tab->wdt && tab->dash)
        ft_left_cs(tab, 0);
*/
}

void	ft_print_ptr(t_print *tab, char *ptr)
{
	if (tab->spec == 'p')
		tab->totlen += write(FD, "0x", 2);
	tab->totlen += write(FD, ptr, ft_strlen(ptr));
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
