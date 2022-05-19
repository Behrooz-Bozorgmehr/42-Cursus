/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 12:47:15 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/19 20:15:40 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int	ft_num_len(uintptr_t n, unsigned int base )
{
	int	i;
	
	i = 1;
	while (n >=  base)
	{
		i++;
		n = n / base;
	}
	return (i);
}

void	ft_fill(char *ptr, uintptr_t n, t_print *tab, char spec)
{
	int		remain;
	int		len;
	int 	base;
	char	c;
	base = 10;
	if (spec == 'x' || spec == 'X' || spec == 'p')
		base = 16;
	else if (spec == 'o')
		base = 8;
	len = ft_num_len(n, base);
	if (n == 0)
		ptr[0] = '0';	
	while (n > 0)
	{
		remain = n % base;
		if (spec== 'X' && remain > 9)
			c = (char)ft_toupper(HEXA_TABLE[remain]);
		else
			c = HEXA_TABLE[remain];
		ptr[ft_num_len(n, base) - 1] = c;
		n = n / base;
	}
	ptr[len] = '\0';
	ft_print_ptr(tab, ptr);
}

void	ft_convert_and_print(t_print *tab)
{
	char	*retval;
	int		num_len;
	char	c;
	unsigned long long n;

	c = tab->spec;
	n = 0;
	if (c == 'p')
		n = va_arg(tab->args, unsigned long long );
	else if (c == 'x' || c == 'X' || c == 'u' || c == 'o')
		n = va_arg(tab->args, unsigned int);
	if (c == 'p' || c == 'x' || c == 'X')
		num_len = ft_num_len(n, 16);
	else if(c == 'o')
		num_len = ft_num_len(n, 8);
	else
		num_len = ft_num_len(n, 10);
	retval = (char *) malloc(sizeof(char) * (num_len + 1));
	if (retval != NULL)
		ft_fill(retval, n, tab, (char)c);
}

int	ft_is_spec(char c)
{
	int	i;

	i = 0;
	while (i < SPECLENT)
	{
		if (SPEC[i] == c)
			return (1);
		i++;
	}
	return (0);
}
