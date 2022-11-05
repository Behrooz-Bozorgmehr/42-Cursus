/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 14:23:28 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/03/01 19:20:03 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		j = 0;
		k = i;
		while (haystack[k] == needle[j] && k < len)
		{
			if (needle[j + 1] == '\0')
				return ((char *)&haystack[i]);
			j++;
			k++;
		}
		i++;
	}
	return (NULL);
}

/*
 The strnstr() function locates the first occurrence of the
 null-terminated string needle in the string haystack, where
 not more than len characters are searched. 
 Characters that appear after a `\0' character are not searched.
 Since the strnstr() function is a FreeBSD specific API, it should
 only be used when portability is not a concern.

 While the strcasestr() function uses the current locale,
 the strcasestr_l() function may be passed a
 locale directly. See xlocale(3) for more information.
	
 RETURN VALUES
 If needle is an empty string, haystack is returned;
 if needle occurs nowhere in haystack, NULL is returned; otherwise
 a pointer to the first character of the first occurrence of needle
 is returned.
 */

/*

#include <stdio.h>
#include <string.h>

int	main(void)
{
//	printf("%s\n", strnstr("Find the needle in the haystack","needle", 20));
//	printf("%s\n", ft_strnstr("Find the needle in the haystack","needle", 20));
	char	*ptr;
	char	*str;
	char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";

	ptr = ft_strnstr(haystack, needle, -1); 
	str = strnstr(haystack, needle, -1);
	printf("ptr is : @%s@\n", ptr);
	printf("str is : @%s@\n", str);

	ptr = NULL;
	str = NULL;
	ptr = ft_strnstr(haystack, "abcd", 9) ;
   	str = haystack + 5;
	printf("ptr is : @%s@\n", ptr);
	printf("str is : @%s@\n", str);
	

	return (0);
}*/
