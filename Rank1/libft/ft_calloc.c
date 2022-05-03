/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:35:06 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/19 14:28:05 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (void *) malloc(count * size);
	if (ptr != NULL)
	{
		while (i < count * size)
		{
			ptr[i] = 0;
			i++;
		}
	}
	return ((void *)ptr);
}

/* The calloc() function contiguously allocates enough space for count
     objects that are size bytes of memory each and returns a pointer to the
     allocated memory.  The allocated memory is filled with bytes of value
     zero.
*/
/*

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*ptr;
	char	*str;
	ptr =  (char *) ft_calloc(20, 4);
	str = (char *) calloc(20, 4);
	printf("%p\n", ptr);
	printf("%s\n", ptr);
	printf("%p\n", ptr + 40);


	printf("%p\n", str);
	printf("%s\n", str);
	printf("%p\n", str + 40);

	return (0);
}
*/
