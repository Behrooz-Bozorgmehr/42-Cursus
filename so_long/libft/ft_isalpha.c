/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 10:53:42 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/08 21:02:37 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%d ", ft_isalpha('b'));
	printf("%d ", ft_isalpha('B'));
	printf("%d ", ft_isalpha('2'));
	printf("%d ", ft_isalpha('\\'));
	printf("%d ", ft_isalpha(' '));
	return (0);
}
*/
