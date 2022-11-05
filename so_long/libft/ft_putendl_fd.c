/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:50:51 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/20 16:55:29 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, s + i, 1);
		i++;
	}
	write(fd, "\n", 1);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	ft_putendl_fd("thiaikdfkdakfjdfdakfieirll", 1);
	ft_putendl_fd("thiaikdfkdakfjdfdakfieirll", 1);
	return (0);
}
*/
