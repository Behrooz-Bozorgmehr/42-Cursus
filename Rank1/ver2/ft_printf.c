/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 07:21:09 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/21 03:57:31 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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

void	ft_print_val(t_print *tab, char c)
{
	char	*ptr;

	tab->spec = c;
	if ( c == '%')
		ft_update_tab(tab, write(FD, "%", 1));
	if (c == 'c')
		ft_print_char(tab);
	else if (c == 's')
		ft_print_str(tab);
	else if (c == 'x' || c == 'X' || c == 'p' || c == 'o' || c == 'u')
		ft_convert_and_print(tab);
	else if (c == 'd' || c == 'i')
	{
		ptr = ft_itoa(va_arg(tab->args, int));
		ft_print_ptr(tab,ptr);
	}
}

int	ft_to_my_number(const char *str, int sign)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
		if (num == 214748364 && str[i] <= '7')
		{
			num = num * 10 + str[i] - '0';
			break ;
		}
		if (num == 214748364 && str[i] == '8' && sign == -1)
			return (-2147483648);
		if (num >= 214748364 && (str[i] >= '0' && str[i] <= '9'))
		{
			if (sign == -1)
				return (0);
			return (-1);
		}	
	}
	return (num * sign);
}

int	ft_my_atoi(const char *str)
{
	size_t	i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == '.')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i] == '-');
		i++;
	}
	num = ft_to_my_number(str + i, sign);
	return (num);
}

int	ft_eval_format(t_print *tab, const char *format, int i)
{
	char	c;

	c = format[i];
	tab->wdt = ft_my_atoi(format + i);
	tab->precision = ft_my_atoi(format + i);
	while (ft_is_spec(c) == 0)
	{
		if (c  == '-')
		 	tab->dash = 1;
		else if (c == '+')
			tab->sign = 1;
		else if (c == '#')
			tab->htag = 1; 
		else if (c == '0')
			tab->is_zero = 1;
		else if (c == '.')
			tab->point = 1;
		else if (c == ' ')
			tab->sp = 1;

		i++;
		c = format[i];
	}
//	if (tab->point > 0)
//		tab->precision = ft_atoi(format + i - 1 );

	if (tab->wdt < 0)
		tab->wdt *= -1;
	ft_print_val(tab, c);
	return (i);
}

int ft_printf(const char *format, ...)
{
   int i;
   int ret;
   t_print *tab;
                       
   tab = (t_print *)malloc(sizeof(t_print));                        
   if (!tab)                         
       return (-1);
   ft_init(tab);
   va_start(tab->args, format);
   i = -1;
   ret = 0;
   while (format[++i]) 
   { 
      if (format[i] == '%')
		  i = ft_eval_format(tab, format, i + 1);
      else
         ret += write(1, &format[i], 1);
   }
    va_end(tab->args);
    ret += tab->totlen;
    free (tab);
	tab = NULL;
    return (ret);
}

