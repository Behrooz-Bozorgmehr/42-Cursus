/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:31:59 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/03/01 18:53:24 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t len)
{
	char	*dstptr;
	char	*srcptr;
	size_t	i;

	if (len == 0 || dst == src)
		return (dst);
	dstptr = (char *)dst;
	srcptr = (char *)src;
	i = 0;
	while (i < len)
	{
		dstptr[i] = srcptr[i];
		i++;
	}
	dst = (void *)dstptr;
	return (dst);
}
/*

DESCRIPTION
     The memcpy() function copies n bytes from memory area src to memory area
     dst.  If dst and src overlap, behavior is undefined.  Applications in
     which dst and src might overlap should use memmove(3) instead.

RETURN VALUES
     The memcpy() function returns the original value of dst.
*/
