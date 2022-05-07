/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:34:20 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/07 17:36:39 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_add_zpace(va_list args, const char *format)
{
	int		len;
	int		i;
	char	*ptr;

	i = 0;
	len = ft_atoi(format);
	ptr = ft_itoa(va_arg(args, int));
	i = len - ft_strlen(ptr);
	while (i > 0)
	{
		ft_print_char(format[0]);
		i--;
	}
	ft_print_ptr(ptr);
	return (len);
}

int	ft_hashtag(va_list args, const char *format, int i)
{
	int		len;
	char	*ptr;

	len = ft_print_char('0');
	if (format[i] == 'x' || format[i] == 'X')
	{
		ptr = ft_convert_num(va_arg(args, unsigned int), 16, format[i]);
		if (*ptr > '0')
		{
			len += ft_print_char(format[i]);
			len += ft_print_ptr(ptr);
		}
		else
			ft_free_ptr(ptr);
	}
	else
	{
		ptr = ft_convert_num(va_arg(args, unsigned int), 8, format[i]);
		if (*ptr > '0')
			len += ft_print_ptr(ptr);
		else
			ft_free_ptr(ptr);
	}
	return (len);
}

int	ft_print_ptr(char *ptr)
{
	int	len;

	len = write(FD, ptr, ft_strlen(ptr));
	ft_free_ptr(ptr);
	return (len);
}

int	ft_print_str(char *str)
{
	int	len;

	if (str == NULL)
		str = "(null)";
	len = write(FD, str, ft_strlen(str));
	return (len);
}

int	ft_print_char(char c)
{
	return (write(FD, &c, 1));
}

/*
int	ft_flag_manager(char *ptr, char spec, char flag)
{
	int		len;
	long	value;

	len = 0;
	value = ft_ptr_value(ptr);
	if (flag == '+' && value >= 0)
		len += write(1, "+", 1);
	else if (flag == '#' && value != 0)
	{
		if (spec == 'o')
			len += write(1, "0", 1);
		else if (spec == 'x')
			len += write(1, "0x", 2);
		else if (spec == 'X')
			len += write(1, "0X", 2);
	}
	else if (flag == '#')
	{
		if (spec == 'a' || spec == 'A' || spec == 'e'
			|| spec == 'E' || spec == 'f'
			|| spec == 'F' || spec == 'g' || spec == 'G')
//		len += forced_decimal_point(value, specifier);
			len = 0;
	}
	return (len);
}
*/
