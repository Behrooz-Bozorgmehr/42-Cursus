/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:51:45 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/20 15:55:39 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

/*
 DESCRIPTION
     The atoi() function converts the initial portion of the string 
	 pointed to by str to int representa-
     tion.

     It is equivalent to:

           (int)strtol(str, (char **)NULL, 10);
*/
/*

#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", atoi("   210051klmni"));
	printf("%d\n\n", ft_atoi("   210051klmni"));

	printf("%d\n", atoi("  * 210051klmni"));
	printf("%d\n\n", ft_atoi("  * 210051klmni"));

	printf("%d\n", atoi("  *210051klmni"));
	printf("%d\n\n", ft_atoi("  *210051klmni"));

	printf("%d\n", atoi("  ++210051klmni"));
	printf("%d\n\n", ft_atoi(" ++ 210051klmni"));

	printf("%d\n", atoi("  --210051klmni"));
	printf("%d\n\n", ft_atoi(" --210051klmni"));

	printf("%d\n", atoi("  +-210051klmni"));
	printf("%d\n\n", ft_atoi(" +-210051klmni"));

	printf("%d\n", atoi("  ( 210051klmni"));
	printf("%d\n\n", ft_atoi(" ( 210051klmni"));

	printf("%d\n", atoi("  /' 210051klmni"));
	printf("%d\n\n", ft_atoi(" /' 210051klmni"));

	printf("%d\n", atoi("  +210051klmni"));
	printf("%d\n\n", ft_atoi("  +210051klmni"));

	printf("%d\n", atoi("  -210051klmni"));
	printf("%d\n\n", ft_atoi("  -210051klmni"));

	printf("%d\n", atoi("  + 210051klmni"));
	printf("%d\n\n", ft_atoi(" + 210051klmni"));
	
	printf("%d\n", atoi("  +2147483649"));
	printf("%d\n\n", ft_atoi(" +2147483649"));
	
	printf("%d\n", atoi("  -2147483649"));
	printf("%d\n\n", ft_atoi(" -2147483649 "));
	
	char	n[40] = "99999999999999999999999999";
	int		i1 = atoi(n);
	int		i2 = ft_atoi(n);
	printf("atoi: %d\n", atoi(n));
	printf("ft_atoi%d\n", ft_atoi(n));
	if (i1 == i2)
		printf("Successful");
	return (0);
}
*/
