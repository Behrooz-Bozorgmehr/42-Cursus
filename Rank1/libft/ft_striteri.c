/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:04:17 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/08 21:27:14 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL || f == NULL)
		return ;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char 	*str = "0123456789abcdefghi *-+klmnop";
	ft_striteri(str, *f);
	printf("%s\n", str);
	return (0);
}
*/
