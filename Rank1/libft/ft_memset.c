/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:18:30 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/18 16:19:59 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)str;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	str = (void *)ptr;
	return (str);
}
/*
 DESCRIPTION
     The memset() function writes len bytes of value c (converted to an
     unsigned char) to the string b.

RETURN VALUES
     The memset() function returns its first argument.
*/
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*ptr;

	printf("%s\n", ft_memset(ptr, 48, 10));
	printf("%s\n", memset(ptr, 49, 10));
	return (0);
}
*/
