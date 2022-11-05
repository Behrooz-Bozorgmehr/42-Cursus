/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:45:58 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/08 21:25:08 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ptr;
	int		i;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	ptr = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	if (ptr != NULL)
	{
		while (s[i] != '\0')
		{
			ptr[i] = f(i, s[i]);
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}
/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	char 	*str = "0123456789abcdefghiklmnop";
	char	*str1;
	str1 = ft_strmapi(str, *f);
	printf("%s\n", str1);
	return (0);
}
char f(unsigned int i, char c)
{
	char str;
	str = c + i % 10 ;
	return (str);
}
*/
