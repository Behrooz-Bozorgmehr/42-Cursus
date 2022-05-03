/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:00:20 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/19 18:20:18 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%d ", ft_isdigit('B'));
	printf("%d ", ft_isdigit('2'));
	printf("%d ", ft_isdigit('\\'));
	printf("%d ", ft_isdigit(' '));
	return (0);
}
*/
