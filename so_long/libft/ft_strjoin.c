/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:07:03 by bbozorgm          #+#    #+#             */
/*   Updated: 2021/12/19 14:47:14 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	join = (char *) malloc((len + 1) * sizeof(char));
	if (join != NULL)
	{
		while (i < len)
		{
			if (i < ft_strlen(s1))
				join[i] = s1[i];
			else
				join[i] = s2[j++];
			i++;
		}
		join[i] = '\0';
	}
	return (join);
}

/*

#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*ptr;
	ptr = ft_strjoin("This is a test", "Here we join to strings");

	printf("%s\n", ptr);
	return 0;
}
*/
