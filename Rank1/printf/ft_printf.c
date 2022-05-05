/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:49:12 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/05 21:59:40 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_more_conditions(va_list args, const char *format, int i)
{
	int		len;
	char	*ptr;
	len = 0;

	if ((format[i] == '-' || format[i] == '+') && (format[i + 1] == 'd'
				|| format[i + 1 ] == 'i'))
	{		ptr = ft_itoa(va_arg(args, int));
		if (ft_atoi(ptr) >= 0)		
		{
			len = ft_print_char(format[i++]);
			len += ft_print_ptr(ptr);
		}
		else
		{
			len = ft_print_ptr(ptr);
		}
	}
	else if (format[i] == '#' && (format[i + 1] == 'x'
				|| format[i + 1] == 'X'))
	{
		len = ft_print_char('0');
		ptr = ft_convert_num(va_arg(args, unsigned int), 16, format[i + 1]);
		if (*ptr > '0')
		{
			len += ft_print_char(format[i + 1]);
			len += ft_print_ptr(ptr);
		}
		else
		{
			free(ptr);
			ptr = NULL;
		}	
	}
	else if (format[i] == '#' && format[i + 1] == 'o')
	{
		len = ft_print_char('0');
		len += ft_switch_spec_others(args, format[++i]); 
	}
	else if (format[i] == '0' || format[i] == ' ' )
	    len = ft_add_zpace(args, format + i);	
	return (len);
}

int	ft_read_format(va_list args, const char *format)
{
	static int		i;
	int		len;

	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
			if (format[i] == '%')
		{
			if (format[++i] == '%')
				len += write(1, &format[i], 1);
			else if (format[i] == '-' || format[i] == '+'
				|| format[i] == '#' || format[i] == '0' || format[i] == ' ' )
			{
				len += ft_more_conditions(args, format, i);
				i++;
			}
			else
				len += ft_switch_spec(args, format[i]);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, format);
	len += ft_read_format(args, format);
	va_end(args);
	return (len);
}
/*
#include <stdio.h>

int main(void)
{

	
	ft_printf(" %X \n", 0);
	ft_printf(" %#x \n", -2147483648);
	printf(" %#x \n", 0);
	printf ("Characters: %c %c \n", 'a', 65);
	 printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: @% 020d@\n", 1977);
   printf ("Some different radices: %d %x %o %000x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");
   return 0;
}	
*/
