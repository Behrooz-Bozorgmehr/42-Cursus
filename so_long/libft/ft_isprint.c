/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:09:17 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/18 16:12:40 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int	main(void)
{
	printf("%d ", ft_isprint('b'));
	printf("%d ", ft_isprint(129));
	printf("%d ", ft_isprint('\n'));
	printf("%d ", ft_isprint('\\'));
	printf("%d ", ft_isprint(' '));
	printf("%s", "\n");
	printf("%d ", isprint('b'));
	printf("%d ", isprint(129));
	printf("%d ", isprint('\n'));
	printf("%d ", isprint('\\'));
	printf("%d ", isprint(' '));

	return (0);
}
*/
