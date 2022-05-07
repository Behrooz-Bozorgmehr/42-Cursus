/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:49:12 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/07 07:04:49 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_sign(va_list args, const char *format, int i)
{
	int		len;
	char	*ptr;

	len = 0;
	ptr = ft_itoa(va_arg(args, int));
	if (ft_ptr_value(ptr) >= 0)
	{
		len = ft_print_char(format[i]);
		i++;
		len += ft_print_ptr(ptr);
	}
	else
		len = ft_print_ptr(ptr);
	return (len);
}

int	ft_more_conditions(va_list args, const char *format, int i)
{
	int		len;
	char	c;

	len = 0;
	c = format[i];
	if ((c == '-' || c == '+') && (format[i + 1] == 'd'
			|| format[i + 1 ] == 'i'))
		len = ft_print_sign(args, format, i);
	else if (c == '#' && (format[i + 1] == 'x'
			|| format[i + 1] == 'X'))
	{
		i++;
		len = ft_hashtag(args, format, i);
	}
	else if (c == '0' || c == ' ' )
		len = ft_add_zpace(args, format + i);
	else if (c == '-')
		len = ft_get_arg(args, format, i);
	return (len);
}

int	ft_read_flag(va_list args, const char *format, int *i)
{
	int		len;
	char	c;

	len = 0;
	c = format[*i];
	if (c == '%')
		len = write(1, &c, 1);
	else if (c == '-' || c == '+' || c == '#' || c == '0' || c == ' ' )
	{
		len = ft_more_conditions(args, format, *i);
		(*i)++;
	}
	else
		len = ft_switch_spec(args, format[*i]);
	return (len);
}

int	ft_read_format(va_list args, const char *format)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_read_flag(args, format, &i);
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
	ft_printf("%-1c\n", '0');
	ft_printf(" %-2c\n", '0');
	ft_printf(" %-3c\n ", '0' - 256);
	ft_printf("%-4c\n ", '0' + 256);
	ft_printf(" %-1c %-2c %-3c\n ", '0', 0, '1');
	ft_printf(" %-1c %-2c %-3c\n", ' ', ' ', ' ');
	ft_printf(" %-1c %-2c %-3c\n ", '1', '2', '3');
	ft_printf(" %-1c %-2c %-3c\n ", '2', '1', 0);
	ft_printf(" %-1c %-2c %-3c\n ", 0, '1', '2');

	ft_printf("%1s\n", "");
	ft_printf("%-1s\n", "");
	ft_printf(" %-2s\n", "");
	ft_printf("%-3s\n", "");
//	ft_printf(" %-0s\n", "");
	ft_printf(" %-s\n", "-");
	ft_printf(" %-1s %-2s\n", "", "-");
	ft_printf(" %-3s %-4s\n", " - ", "");
	ft_printf(" %-2s %-3s %-4s %-5s\n", " - ", "", "4", "");
	ft_printf(" %-3s %-3s %-4s %-5s %-3s\n", " - ", "", "4", "", "2 ");

//	ft_printf(" %2p\n", -1);
//	ft_printf(" %-2p\n", -1);
//	ft_printf(" %-2p\n", 1);
//	ft_printf(" %-2p\n", 15);
//	ft_printf(" %-3p\n", 16);
//	ft_printf(" %-4p\n", 17);
	
	ft_printf(" %-1d\n", 0);
	ft_printf(" %-2d\n", -1);
	ft_printf(" %-3d\n", 1);
	ft_printf(" %-4d\n", 9);
	ft_printf(" %-1d\n", 10);
	ft_printf(" %-2d\n", 11);
	ft_printf(" %-3d\n", 15);
	ft_printf(" %-4d\n", 16);
	ft_printf(" %-5d\n", 17);
	ft_printf(" %-1d\n", 99);
	ft_printf(" %-2d\n", 100);
	ft_printf(" %-3d\n", 101);
	ft_printf(" %-1d\n", -9);
	ft_printf(" %-2d\n", -10);
	ft_printf(" %-3d\n", -11);
	ft_printf(" %-4d\n", -14);
	ft_printf(" %-5d\n", -15);
	ft_printf(" %-6d\n", -16);
	ft_printf(" %-1d\n", -99);
	ft_printf(" %-2d\n", -100);
	ft_printf(" %-3d\n", -101);
	
	ft_printf(" %-1i\n", 0);
	ft_printf(" %-2i\n", -1);
	ft_printf(" %-3i\n", 1);
	ft_printf(" %-4i\n", 9);
	ft_printf(" %-1i\n", 10);
	ft_printf(" %-2i\n", 11);
	ft_printf(" %-3i\n", 15);
	ft_printf(" %-4i\n", 16);
	ft_printf(" %-5i\n", 17);
	ft_printf(" %-1i\n", 99);
	ft_printf(" %-2i\n", 100);
	ft_printf(" %-3i\n", 101);
	ft_printf(" %-1i\n", -9);
	ft_printf(" %-2i\n", -10);
	ft_printf(" %-3i\n", -11);
	ft_printf(" %-4i\n", -14);
	ft_printf(" %-5i\n", -15);
	ft_printf(" %-6i\n", -16);
	ft_printf(" %-1i\n", -99);
	ft_printf(" %-2i\n", -100);
	ft_printf(" %-3i\n", -101);
	
	ft_printf(" %-1u\n", 0);
	ft_printf(" %-2u\n", -1);
	ft_printf(" %-3u\n", 1);
	ft_printf(" %-4u\n", 9);
	ft_printf(" %-1u\n", 10);
	ft_printf(" %-2u\n", 11);
	ft_printf(" %-3u\n", 15);
	ft_printf(" %-4u\n", 16);
	ft_printf(" %-5u\n", 17);
	ft_printf(" %-1u\n", 99);
	ft_printf(" %-2u\n", 100);
	ft_printf(" %-3u\n", 101);
	ft_printf(" %-1u\n", -9);
	ft_printf(" %-2u\n", -10);
	ft_printf(" %-3u\n", -11);
	ft_printf(" %-4u\n", -14);
	ft_printf(" %-5u\n", -15);
	ft_printf(" %-6u\n", -16);
	ft_printf(" %-1u\n", -99);
	ft_printf(" %-2u\n", -100);
	ft_printf(" %-3u\n", -101);
	
	ft_printf(" %-1x\n", 0);
	ft_printf(" %-2x\n", -1);
	ft_printf(" %-3x\n", 1);
	ft_printf(" %-4x\n", 9);
	ft_printf(" %-1x\n", 10);
	ft_printf(" %-2x\n", 11);
	ft_printf(" %-3x\n", 15);
	ft_printf(" %-4x\n", 16);
	ft_printf(" %-5x\n", 17);
	ft_printf(" %-1x\n", 99);
	ft_printf(" %-2x\n", 100);
	ft_printf(" %-3x\n", 101);
	ft_printf(" %-1x\n", -9);
	ft_printf(" %-2x\n", -10);
	ft_printf(" %-3x\n", -11);
	ft_printf(" %-4x\n", -14);
	ft_printf(" %-5x\n", -15);
	ft_printf(" %-6x\n", -16);
	ft_printf(" %-1x\n", -99);
	ft_printf(" %-2x\n", -100);
	ft_printf(" %-3x\n", -101);

	ft_printf(" %-1x\n", 0);
	ft_printf(" %-2x\n", -1);
	ft_printf(" %-3x\n", 1);
	ft_printf(" %-4x\n", 9);
	ft_printf(" %-1x\n", 10);
	ft_printf(" %-2x\n", 11);
	ft_printf(" %-3x\n", 15);
	ft_printf(" %-4x\n", 16);
	ft_printf(" %-5x\n", 17);
	ft_printf(" %-1x\n", 99);
	ft_printf(" %-2x\n", 100);
	ft_printf(" %-3x\n", 101);
	ft_printf(" %-1x\n", -9);
	ft_printf(" %-2x\n", -10);
	ft_printf(" %-3x\n", -11);
	ft_printf(" %-4x\n", -14);
	ft_printf(" %-5x\n", -15);
	ft_printf(" %-6x\n", -16);
	ft_printf(" %-1x\n", -99);
	ft_printf(" %-2x\n", -100);
	ft_printf(" %-3x\n", -101);
	
   return 0;
}	
*/
