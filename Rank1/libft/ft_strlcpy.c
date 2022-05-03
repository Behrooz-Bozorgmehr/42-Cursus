/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:19:27 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/23 18:14:33 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && (i + 1 < dstsize))
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	dst1[40] = "1234567890";
	char	dst2[40] = "1234567890";
	char	src[50] = "abcdefghijklmnopqrstuvwxyz";
	printf("%zu\n",ft_strlcpy(dst1 , src,25));
	printf("%zu\n",strlcpy(dst2 , src,25));
	printf("%s\n", dst1);
	printf("%s\n", dst2);

	return (0);
}
*/
