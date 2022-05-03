/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:04:43 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/19 18:18:06 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%d ", ft_isalnum('b'));
	printf("%d ", ft_isalnum('B'));
	printf("%d ", ft_isalnum('2'));
	printf("%d ", ft_isalnum('\\'));
	printf("%d ", ft_isalnum(' '));
	return (0);
}
*/
