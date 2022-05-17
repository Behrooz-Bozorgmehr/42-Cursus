/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 07:21:09 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/17 21:25:32 by bbozorgm         ###   ########.fr       */
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

int	ft_eval_format(t_print *tab, const char *format, int i)
{
	char	c;

	c = format[i];
	tab->wdt = ft_atoi(format + i);
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
}/*
#include <stdio.h>
int main()
{


//printf("no: %d\n", printf("(%-2s)(%-3s)(%-4s)(%-5s)\n", " - ", "5", "4", ""));

//printf("n:%d\n",ft_printf("(%-2s)(%-3s)(%-4s)(%-5s)\n", " -", "5", "4", ""));


//printf("no: %d\n", printf(" %-3s %-3s %-4s %-5s %-3s\n", " - ", "", "4", "", "2 "));
//printf("n: %d\n", ft_printf(" %-3s %-3s %-4s %-5s %-3s\n", " - ", "", "4", "", "2 "));
  printf("n: %d\n", ft_printf("(%p)(%p)\n", -1, 2147483647));

  printf("n: %d\n", ft_printf("(%p)(%p)\n", 9223372036854775807, -9223372036854775807));

	printf("%d\n", ft_num_len(-2147483648, 16));
	printf("%d\n", ft_num_len(2147483647, 16));
	
	printf("%d\n", ft_num_len(-2147483647, 16));
	printf("%d\n", ft_num_len(-1, 16));

	printf("%d\n", ft_num_len(-9223372036854775807, 16));
	printf("%d\n", ft_num_len(9223372036854775807, 16));


	return (0);
}
*/
