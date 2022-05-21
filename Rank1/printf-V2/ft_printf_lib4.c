/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_lib4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:27:15 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/21 10:19:41 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write_condition(t_print *tab, char *ptr, int len)
{
	char	spec;

	spec = tab->spec;
	if (tab->spec == 'p')
		write(FD, "0x", 2);
	else if ((spec == 'd' || spec == 'i') && tab->sign > 0 && (*ptr >= '0'))
		tab->totlen += write(FD, "+", 1);
	else if ((spec == 'd' || spec == 'i' || spec == 'u' || spec == 'x'
			|| spec == 'X') && tab->sp > 0 && (*ptr >= '0'))
		tab->totlen += write(FD, " ", 1);
	if (tab->htag > 0 && (spec == 'x' || spec == 'X') && (*ptr > '0'))
	{
		tab->totlen += write(FD, "0", 1);
		tab->totlen += write(FD, &tab->spec, 1);
	}
	if (*ptr < '0' && ((len < tab->wdt && !tab->dash)
			|| (len <= tab->precision)))
		write(FD, ptr + 1, ft_strlen(ptr + 1));
	else
		write(FD, ptr, ft_strlen(ptr));
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

int	ft_atoi_and_dot(const char *str)
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
