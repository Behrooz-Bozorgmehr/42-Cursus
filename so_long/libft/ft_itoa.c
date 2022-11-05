/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 14:38:12 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/20 14:58:26 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_size(int n)
{
	int	counter;

	counter = 0;
	if (n <= 0)
		counter++;
	while (n != 0)
	{
		n = n / 10;
		counter++;
	}
	return (counter);
}

char	*ft_to_string(char *ptr, unsigned int n, unsigned int digits)
{
	ptr[digits] = '\0';
	if (n == 0)
		ptr[0] = '0';
	while (n > 0)
	{
		ptr[digits - 1] = (n % 10) + '0';
		n = n / 10;
		digits--;
	}
	return (ptr);
}		

char	*ft_itoa(int n)
{
	char			*ptr;
	unsigned int	digits;
	unsigned int	nbr;

	ptr = NULL;
	digits = ft_size(n);
	ptr = (char *) malloc((digits + 1) * sizeof(char));
	if (ptr != NULL)
	{
		if (n < 0)
		{
			ptr[0] = '-';
			nbr = -1 * n;
		}
		else
			nbr = n;
		ptr = ft_to_string(ptr, nbr, digits);
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*ptr;
	ptr = ft_itoa(-623);
	printf("%s\n", ptr);
	ptr = ft_itoa(156);
	printf("%s\n", ptr);
	ptr = ft_itoa(-0);
	printf("%s\n", ptr);
	ptr = ft_itoa(0);
	printf("%s\n", ptr);
	ptr = ft_itoa(-2147483647);
	printf("%s\n", ptr);
	ptr = ft_itoa(2147483647);
	printf("%s\n", ptr);
	ptr = ft_itoa(10002080);
	printf("%s\n", ptr);
	ptr = ft_itoa(-10002080);
	printf("%s\n", ptr);
	ptr  = ft_itoa(-2147483648);
	printf("@%s@\n", ptr);
	printf("%d\n", ft_atoi(ptr));
	return (0);
}
*/
