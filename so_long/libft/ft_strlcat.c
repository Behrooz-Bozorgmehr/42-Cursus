/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 12:08:15 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/23 18:13:59 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;
	size_t	retval;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (dstlen >= dstsize)
		retval = dstsize + srclen;
	else
		retval = dstlen + srclen;
	while ((dstlen + 1 < dstsize) && src[i] != '\0')
	{
		dst[dstlen] = src[i];
		i++;
		dstlen++;
	}
	dst[dstlen] = '\0';
	return (retval);
}
/*   strlcat() appends string src to the end of dst.  It will append at most
     dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, unless
     dstsize is 0 or the original dst string was longer than dstsize (in prac-
     tice this should not happen as it means that either dstsize is incorrect
     or that dst is not a proper string).

     If the src and dst strings overlap, the behavior is undefined.
*/
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*src = "the cake is a lie !\0I-m hidden lol\r\n";
	char	dst1 [256] = "there is no stars in the sky";
	char	dst2 [256] = "there is no stars in the sky";
	size_t	max = ft_strlen(src) + 4 ;
	printf("srclen:%zu\n", ft_strlen(src));
	printf("srclen:%zu\n", strlen(src));
	
	printf("dstlen:%zu\n", ft_strlen(dst1));
	printf("dstlen:%zu\n", strlen(dst2));

	printf("%zu\n", ft_strlcat(dst1 , src, max));
	printf("%zu\n", strlcat(dst2 , src, max));
	
	printf("%s\n", dst1);
	printf("%s\n", dst2);
	printf("comp result: %d\n", strcmp(dst1, dst2));
	return (0);
}
*/
