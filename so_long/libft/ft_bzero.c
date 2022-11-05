/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 11:24:46 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/18 16:43:53 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;
	size_t	i;

	ptr = (char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = '\0';
		i++;
	}
	s = (void *)ptr;
}
/*
 DESCRIPTION
     The bzero() function writes n zeroed bytes to the string s.  If n is
     zero, bzero() does nothing.
*/
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*ptr;
	ft_bzero(ptr, 10);
	printf("%s\n", ptr);
	bzero(ptr, 20);
	printf("%s\n", ptr);
	return (0);
}
*/
