/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:54:39 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/03 15:31:30 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_fill(char *join, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (s1[++i] != '\0')
		join[i] = s1[i];
	while (s2[j] != '\0')
		join[i++] = s2[j++];
	join[i] = '\0';
}

char	*ft_strjoin_and_free(char *s1, char *s2)
{
	char	*join;
	size_t	len;

	if (s1 == NULL)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = (char *) malloc((len + 1) * sizeof(char));
	if (join == NULL)
		return (NULL);
	ft_fill(join, s1, s2);
	free(s1);
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	char	cr;
	size_t	i;
	size_t	len;

	if (s == NULL)
		return (NULL);
	cr = (char)c;
	i = 0;
	len = ft_strlen(s);
	if (cr == '\0')
		return ((char *)(s + len));
	while (i < len)
	{
		if (s[i] == cr)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

char	*free_ptr(char *str)
{
	free(str);
	str = NULL;
	return (NULL);
}
