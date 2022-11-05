/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 13:42:53 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/13 20:55:04 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_start(char const *s1, char const *set)
{	
	size_t	start;
	size_t	length;

	start = 0;
	length = ft_strlen(s1);
	while (start < length)
	{
		if (ft_strchr(set, s1[start]) == NULL)
			break ;
		start++;
	}
	return (start);
}

size_t	ft_end(char const *s1, char const *set)
{
	size_t	end;
	size_t	length;

	length = ft_strlen(s1);
	end = 0;
	while (end < length)
	{
		if (ft_strchr(set, s1[length - end - 1]) == NULL)
			break ;
		end++;
	}
	return (length - end);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *) malloc(sizeof(char) * (n + 1));
	if (ptr != NULL)
	{
		while (i < n)
		{
			ptr[i] = s1[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	start;
	size_t	end;
	size_t	length;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	length = end - start;
	ptr = ft_strndup(s1 + start, length);
	return (ptr);
}
/*
 	function trim front side if needed, then copies up to 
	str.length -  trim.length, then if back side also includes
   	trim-set copy action stops here otherwise the last charachters
   	are also copied to the string before return it. 	
 */
/*
#include <string.h>
#include <stdio.h>
int	main(void)
{
	printf("Begin");
char const *s1 = " \t \n\n \t\t  \n\n\nHello \t 
Please\n Trim me !\n   \n \n \t\t\n  ";

	char	*set = " \n\t";
	printf("%sHere", ft_strtrim(s1, set));
	return (0);
}
*/
