/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:38:47 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/07 17:34:26 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_len(unsigned long long n, int base )
{
	int	i;

	i = 1;
	while (n >= (unsigned int) base)
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
	len = ft_num_len(n, base);
	while (n > 0)
	{
		remain = n % base;
		if (form == 'X' && remain > 9)
			c = (char)ft_toupper(HEXA_TABLE[remain]);
		else
			c = HEXA_TABLE[remain];
		ptr[ft_num_len(n, base) - 1] = c;
		n = n / base;
	}
	ptr[len] = '\0';
	return (ptr);
}

char	*ft_convert_num(unsigned long long n, int base, char form)
{
	char	*retval;
	int		len;

	retval = NULL;
	len = ft_num_len(n, base);
	if (n == 0)
		return (ft_strndup("0", 1));
	retval = (char *) malloc(sizeof(char) * (len + 1));
	if (retval != NULL)
		retval = fill_ptr(retval, n, base, form);
	return (retval);
}

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
