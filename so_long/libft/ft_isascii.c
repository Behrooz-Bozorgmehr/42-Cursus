/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isascii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:15:31 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/18 16:07:42 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%d ", ft_isascii('b'));
	printf("%d ", ft_isascii('"'));
	printf("%d ", ft_isascii('2'));
	printf("%d ", ft_isascii('\\'));
	printf("%d ", ft_isascii(129));
	return (0);
}
*/
