/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:24:27 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/06 22:48:35 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_free_ptr(char *ptr)
{
	free(ptr);
	ptr = NULL;
	return (ptr);
}

int	ft_get_arg(va_list args, const char *format, int i)
{
	char	c;
	int		len;

	len = 0;
	while (1)
	{
	   c = format[i];	
	   if (c == 'c' || c == 's' || c == 'x' || c == 'X' || c == 'p' || c == 'u')
	   {
		   len = ft_switch_spec(args, c);		 
		   break;
	   }
	   i++;
	}
	return (len);
}
int	ft_switch_spec_others(va_list args, char spec)
{
	int	len;

	len = 0;
	if (spec == 'i' || spec == 'd')
		len = ft_print_ptr(ft_itoa(va_arg(args, int)));
	else if (spec == 'u')
		len = ft_print_ptr(ft_convert_num(
					va_arg(args, unsigned int), 10, '0'));
	else if (spec == 'x' || spec == 'X')
		len = ft_print_ptr(ft_convert_num(
					va_arg(args, unsigned int), 16, spec));
	else if (spec == 'o')
		len = ft_print_ptr(ft_convert_num(
					va_arg(args, unsigned int), 8, 'o'));
	return (len);
}

int	ft_switch_spec(va_list args, char spec)
{
	int		len;

	len = 0;
	if (spec == 'c')
		len = ft_print_char((char ) va_arg(args, int));
	else if (spec == 's')
		len = ft_print_str(va_arg(args, char *));
	else if (spec == 'p')
	{
		len = ft_print_str("0x");
		len += ft_print_ptr(ft_convert_num(
					va_arg(args, unsigned long long), 16, 'x'));
	}
	else
		len = ft_switch_spec_others(args, spec);
	return (len);
}
