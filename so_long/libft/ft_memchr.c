/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:30:07 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/03/01 18:51:49 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	cr;
	char	*str;

	i = 0;
	cr = (char) c;
	str = (char *)s;
	while (i < n)
	{
		if (str[i] == cr)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}

/*
DESCRIPTION
     The memchr() function locates the first occurrence of c (converted to an
     unsigned char) in string s.

RETURN VALUES
     The memchr() function returns a pointer to the byte located, or NULL if no
     such byte exists within n bytes.
*/
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	printf("%p\n", memchr("This is to compare",'o', 25));
	printf("%p\n", ft_memchr("This is to compare", 'o', 25));

	return (0);
}
*/
