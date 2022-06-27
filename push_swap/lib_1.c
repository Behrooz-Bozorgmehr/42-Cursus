/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:58:01 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/06/23 19:46:44 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_to_number(const char *str, int sign)
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

int	ft_atoi(const char *str)
{
	size_t	i;
	int		num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = 1 - 2 * (str[i] == '-');
		i++;
	}
	num = ft_to_number(str + i, sign);
	return (num);
}
