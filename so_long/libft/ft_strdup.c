/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:48:04 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/19 18:25:01 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	ptr = (char *) malloc(sizeof(char) * (len + 1));
	if (ptr != NULL)
	{
		while (i <= len)
		{
			ptr[i] = s1[i];
			i++;
		}
	}
	return (ptr);
}
/*
 DESCRIPTION
     The strdup() function allocates sufficient memory for a copy
	 of the string s1, does the copy, and returns a pointer to it.
   	 The pointer may subsequently be used as an argument to the function
     free(3).
If insufficient memory is available, NULL is returned and errno is set to ENOMEM.
*/
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*ptr;
	char	*str;
	ptr = ft_strdup("This is a \0 test");
	str = strdup("This is a \0 test");

	printf("%s\n", ptr);
	printf("%s\n", str);
	return 0;
}
*/
