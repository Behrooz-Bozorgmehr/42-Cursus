/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:16:34 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/04/19 20:22:37 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
