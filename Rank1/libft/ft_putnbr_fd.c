/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:55:52 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/13 21:11:57 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_counter(int nb)
{
	int	count;

	count = 1;
	while (nb / 10 > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_write_lst_digit(int n, int power, int fd)
{	
	int	retval;
	int	divide;

	divide = 1;
	while (power > 1)
	{
		divide *= 10;
		power--;
	}
	retval = n % divide;
	n = n / divide;
	n = n + 48;
	write(fd, &n, 1);
	return (retval);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		count;

	if (n < 0)
	{	
		if (n == -2147483648)
		{
			write(fd, "-2147483648", 11);
			return ;
		}
		else
		{
			n = -1 * n;
			write(fd, "-", 1);
		}
	}
	count = ft_counter(n);
	while (count > 0)
	{
		n = ft_write_lst_digit(n, count, fd);
		count--;
	}
	write(fd, &n, 1);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	int n = -2147483648;
	ft_putnbr_fd(n, 1);
//	n = 2147483647;
//	ft_putnbr_fd(n, 1);
		return (0);
}
*/
