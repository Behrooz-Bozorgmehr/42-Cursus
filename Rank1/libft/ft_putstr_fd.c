/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:43:15 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/20 16:49:58 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, s + i, 1);
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	ft_putstr_fd("This", 1);
	ft_putstr_fd("kkdfkkadkfqeriie", 0);
	ft_putstr_fd("f124665578994", 2);
	return (0);
}
*/
