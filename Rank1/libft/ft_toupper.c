/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:27:25 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/18 18:55:58 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int	main(void)
{
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", toupper('c'));

	return (0);
}
*/
