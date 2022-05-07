/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 07:21:09 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/07 20:39:00 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_val(t_print *tab, char c)
{
	tab->spec = c;
	if (c == 'c')
		ft_print_char(tab);
	else if (c == 's')
		ft_print_str(tab);
	else if (c == 'x' || c == 'X' || c == 'p' || c == 'o' || c == 'u')
		ft_convert_and_print(tab);
	else if (c == 'd' || c == 'i')
		ft_print_ptr(tab, ft_itoa(va_arg(tab->args, int)));
}

int	ft_eval_format(t_print *tab, const char *format, int i)
{
	char	c;

	c = format[i];
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
		else if(c == '%')
			tab->pcent = 1;		
		i++;
		c = format[i];
	}
	if (c == '%')
	{	
		tab->totlen += write(FD, "%", 1);
		return (i);
	}
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
int main()
{
   printf ("Characters: %-c %-c \n", 'a', 65);
   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %-d %-ld\n", 1977, 650000L);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %-10d \n", 1977);
  printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %--10d \n", 1977);
   printf ("Preceding with zeros: %10d \n", 1977);
   printf ("Some different radices: %-10d %-x %-o %#x %#o \n", 100, 100, 100, 100, 100);
  printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
    printf ("floats: %-4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: %*d \n", 5, 10);
   printf ("%s \n", "A string");
   return 0;
}
