/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:41:55 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/20 15:00:57 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dst_ptr;
	unsigned char	*src_ptr;

	if (src == NULL && dst == NULL)
		return (NULL);
	dst_ptr = (unsigned char *) dst;
	src_ptr = (unsigned char *) src;
	if (src <= dst)
	{
		while (len--)
			dst_ptr[len] = src_ptr[len];
		return (dst);
	}
	i = 0;
	while (i < len)
	{
		dst_ptr[i] = src_ptr[i];
		i++;
	}
	return (dst);
}
/*
 DESCRIPTION
     The memmove() function copies len bytes from string src to string dst.
     The two strings may overlap; the copy is always done in a non-destructive
     manner.

RETURN VALUES
     The memmove() function returns the original value of dst.
*/
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{

	char	dst1[0xF0];
	char	dst2[0xF0];
	char	*data = "thiß ß\xde\xad\xbe\xeftriñg will be øvérlapéd !\r\n";
	int		size = 0xF0 - 0xF;
	memset(dst1, '.', sizeof(dst1));
	printf("memset1%s\n\n", dst1);
	memcpy(dst1, data, strlen(data));
	printf("memcpy1%s\n\n", dst1);

	memset(dst2, '.', sizeof(dst2));
	printf("memset2%s\n\n", dst2);
	memcpy(dst2, data, strlen(data));
	printf("memcpy2%s\n\n", dst2);
	
	memmove(dst2 + 3, dst2,size);
	ft_memmove(dst1 + 3 , dst1, size);
	printf("memmove%s\n\n", dst2);
	printf("ftmemmove%s\n\n\n\n", dst1);
//	printf("error : %d\n", memcmp(dst1,dst2, size));

	return (0);
}
*/
