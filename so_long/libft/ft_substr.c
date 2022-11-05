/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:58:14 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/23 20:13:31 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	i = 0;
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	sub = (char *) malloc((len + 1) * sizeof(char));
	if (sub != NULL)
	{
		if (start < ft_strlen(s))
		{
			while (i < len)
			{
				sub[i] = s[start + i];
				i++;
			}
		}
		sub[i] = '\0';
	}
	return (sub);
}
/*
#include <stdio.h>
#include <string.h>

int	main(void)
{

	char * s = ft_substr("tripouille", 0, 42000);
   	printf("string is : %s\n", s);

/

	char * str = strdup("1");
	s = ft_substr(str, 42, 42000000);
	mcheck(s, 1); free(s); free(str); showLeaks();
	/
	return 0;
}
*/
