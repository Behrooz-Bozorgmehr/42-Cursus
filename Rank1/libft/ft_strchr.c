/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:12:18 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/03/01 19:06:25 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cr;
	size_t	i;
	size_t	len;

	cr = (char)c;
	i = 0;
	len = ft_strlen(s);
	while (i <= len)
	{
		if (s[i] == cr)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
/*
DESCRIPTION
     The strchr() function locates the first occurrence of c (converted to a
     char) in the string pointed to by s.  The terminating null character is con-
     sidered to be part of the string; therefore if c is `\0', the functions
     locate the terminating `\0'.

     The strrchr() function is identical to strchr(), except it locates the last
     occurrence of c.

RETURN VALUES
     The functions strchr() and strrchr() return a pointer to the located charac-
     ter, or NULL if the character does not appear in the string.
*/
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	printf("%p\n", ft_strchr("This is a test", 't'));
	printf("%p\n", strchr("This is a test", 'a'));

	return (0);
}
*/
