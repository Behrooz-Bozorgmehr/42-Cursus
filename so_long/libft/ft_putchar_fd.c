/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:37:58 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/20 16:42:47 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	ft_putchar_fd('c', 2);
	ft_putchar_fd('d', 0);
	ft_putchar_fd('e', 1);

	return (0);
}
*/
