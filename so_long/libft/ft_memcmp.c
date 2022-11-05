/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:15:55 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/23 18:13:14 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return ((unsigned char) str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
/* 
DESCRIPTION
     The memcmp() function compares byte string s1 against byte string s2.  Both
     strings are assumed to be n bytes lon
	 g

RETURN VALUES
     The memcmp() function returns zero if the two strings are identical, other-
     wise returns the difference between the first two differing bytes (treated
     as unsigned char values, so that `\200' is greater than `\0', for example).
*/
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%d\n", memcmp("","", 10));
	printf("%d\n", ft_memcmp("", "", 10));

	return (0);
}
*/
