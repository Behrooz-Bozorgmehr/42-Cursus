/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:17:36 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/23 19:08:25 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	cr;
	size_t	i;

	len = ft_strlen(s);
	i = len;
	cr = (char) c;
	while ((i <= len) && (i >= 0))
	{
		if (s[i] == cr)
			return ((char *)(s + i));
		i--;
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
//	printf("%p\n", ft_strrchr("We should test the program", 'm'));
//	printf("%p\n", strrchr("We should test the program", 'm'));
	
	char	*ptr;
	char s[] = "tripouille";
	ptr = ft_strrchr(s, 't' + 256);
	printf("ptr is %s\n", ptr);

	return (0);
}
*/
