/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 19:49:12 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/04/28 21:34:06 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int	number_len(unsigned long long n , int base )
{
	int	i;
	
	i = 1;
	while(n >= (unsigned int) base)
	{
		i++;
		n = n / base;
	}	
	return (i);
}

char	*fill_ptr(char *ptr, unsigned long long n, int base, char form)
{
	int		remain;
	char	c;
	int		len;

	remain = 0;
	c = ' ';
	len = number_len(n, base);
	while (n > 0)
	{
		remain = n % base;
		if (form == 'X' && remain > 9)
			c = (char)ft_toupper(HEXA_TABLE[remain]);
		else
			c = HEXA_TABLE[remain];
		ptr[number_len(n, base) - 1] = c;
		n = n / base;
	}
	ptr[len] = '\0'; 
	return (ptr);
}
char	*convert(unsigned long long n, int base, char form)
{
	char	*retval;	
	int		len;

	retval = NULL;
	len = number_len(n, base);	
	if (n == 0)
		return (ft_strndup("0", 1));
	retval = (char *) malloc(sizeof(char) * (len + 1));
	if (retval != NULL)
		retval = fill_ptr(retval, n, base, form);
	return (retval);
}


long	ptr_value(char	*ptr)
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
/*
int	forced_decimal_point(long value, char specifier)
{
	int len;

	len = 0;

	return (len);
}
*/
int	flag_manager(char *ptr, char specifier, char flag)
{
	int		len;
	long	value;

	len = 0;
	value = ptr_value(ptr);
	if (flag == '+' && value >= 0)
		len += write(1, "+", 1);
	else if (flag == '#' && value != 0)
	{
		if (specifier == 'o')
			len += write(1, "0", 1);
		else if (specifier == 'x')
			len += write(1, "0x", 2);
		else if (specifier == 'X')
			len += write(1, "0X", 2);
	}
	else if (flag == '#')
	{
		if (specifier == 'a' || specifier == 'A' || specifier == 'e' || specifier == 'E' ||specifier == 'f' || specifier == 'F' || specifier == 'g' || specifier == 'G')
//		len += forced_decimal_point(value, specifier);	
		len = 0;
	}
	return (len);
}
int	print_ptr(char *ptr)
{
	int	len;

	len = write(FD, ptr, ft_strlen(ptr));
	if (ptr != NULL)
		free(ptr);
	ptr = NULL;
	return (len);
}

int	print_str(char *str)
{
	int	len;

	if (str == NULL)
		str = "(null)";
	len = write(FD, str, ft_strlen(str));
	return (len);
}
int	print_char(char c)
{
	int	len;
	len = write(FD, &c, 1);
	return (len);
}

int	switch_spec(va_list args, char specifier /*, char flag*/)
{
	int		len;
	char	*str;

	str = NULL;
	len = 0;
	if (specifier == 'c')
		len = print_char((char ) va_arg(args, int));
	else if (specifier == 's')
		len = print_str(va_arg(args, char *));
	else if (specifier == 'p')
	{	
		len = print_str("0x");
		len += print_ptr(convert(va_arg(args, unsigned long long), 16, 'x'));
	}
	else if (specifier == 'i' || specifier == 'd')
		len = print_ptr(ft_itoa(va_arg(args,int)));
	else if (specifier == 'u')
		len = print_ptr(convert(va_arg(args, unsigned int), 10, '0'));
	else if (specifier == 'x' || specifier == 'X')
		len = print_ptr(convert(va_arg(args, unsigned int), 16, specifier));
	else if (specifier == 'o')
		len = print_ptr(convert(va_arg(args, unsigned int), 8, 'o'));
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		len;
	char	flag;

	i = 0;
	len = 0;
	flag = '\0';
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[++i] == '%')
				len += write(1, &format[i], 1);
			else if (format[i] == '-' || format[i] == '+' ||
				   	format[i] == '#' || format[i] == '0' || format[i] == ' ')
			{
				flag = format[i];
				len += switch_spec(args, format[++i]/*, flag*/);
				flag = '\0';
			}
			else
				len += switch_spec(args, format[i]/*, flag */);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int INT_MAX = 2147483647;
	int INT_MIN = -2147483648;
	long long LONG_MAX = 9223372036854775807U;
	long long LONG_MIN = -9223372036854775808U;
//	unsigned int UINT_MAX = 4294967295;
	unsigned long ULONG_MAX =  4294967295;

	printf("%d : \n", ft_printf(" %p ", -1));
	printf("%d : \n", ft_printf(" %p ", -1));
	printf("%d : \n", ft_printf(" %p ", -1));
	printf("%d : \n", ft_printf(" %p ", -1));
	printf("%d : \n", ft_printf(" %p ", -1));
	printf("%d : \n", ft_printf(" %p ", -1));
	printf("%d : \n", ft_printf(" %p ", -1));
	printf("%d : \n", ft_printf(" %p ", -1));
	printf("%d : \n", ft_printf(" %p ", -1));
	printf("%d : \n", ft_printf(" %p ", -1));
	printf("%d : \n", ft_printf(" %p ", -1));
	printf("%d : \n", ft_printf(" %p ", 1));
	printf("%d : \n", ft_printf(" %p ", 15));
	printf("%d : \n", ft_printf(" %p ", 16));
	printf("%d : \n", ft_printf(" %p ", 17));
	printf("%d : \n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
	printf("%d : \n", ft_printf(" %p %p ", INT_MIN, INT_MAX));
	printf("%d : \n", ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	printf("%d : \n", ft_printf(" %p %p ", 0, 0));
/
	printf("%d : \n", printf(" %p ", -1));
	printf("%d : \n", printf(" %p ", -1));
	printf("%d : \n", printf(" %p ", -1));
	printf("%d : \n", printf(" %p ", -1));
	printf("%d : \n", printf(" %p ", -1));
	printf("%d : \n", printf(" %p ", -1));
	printf("%d : \n", printf(" %p ", -1));
	printf("%d : \n", printf(" %p ", -1));
	printf("%d : \n", printf(" %p ", -1));
	printf("%d : \n", printf(" %p ", -1));
	printf("%d : \n", printf(" %p ", -1));
	printf("%d : \n", printf(" %p ", 1));
	printf("%d : \n", printf(" %p ", 15));
	printf("%d : \n", printf(" %p ", 16));
	printf("%d : \n", printf(" %p ", 17));
	printf("%d : \n", printf(" %p %p ", LONG_MIN, LONG_MAX));
	printf("%d : \n", printf(" %p %p ", INT_MIN, INT_MAX));
	printf("%d : \n", printf(" %p %p ", ULONG_MAX, -ULONG_MAX));
	printf("%d : \n", printf(" %p %p ", 0, 0));

printf("%%%c   %%%s    %%%d    %%%i   %%%u   %%%x   %%%X   %%%% %%%c   %%%s  %%%d  %%%i  %%%u  %%%x  %%%X  %%%% %%%c  %%%s  %%%d  %%%i  %%%u  %%%x  %%%X  %%%% %c  %%",                                                                                                                           'A',   "42",   42,      42 ,    42 ,  42,    42,         'B',  "-42", -42, -42 ,  -42 , -42,   42,       'C', "0",   0,    0 ,   0 ,    0,   42,     0      );	
	printf("\n\n\n\n");
ft_printf("%%%c   %%%s    %%%d    %%%i   %%%u   %%%x   %%%X   %%%% %%%c   %%%s  %%%d  %%%i  %%%u  %%%x  %%%X  %%%% %%%c  %%%s  %%%d  %%%i  %%%u  %%%x  %%%X  %%%% %c  %%",                                                                                                                           'A',   "42",   42,      42 ,    42 ,  42,    42,         'B',  "-42", -42, -42 ,  -42 , -42,   42,       'C', "0",   0,    0 ,   0 ,    0,   42,     0      );	
	printf("\n\n\n\n");
	return (0);
}
*/

