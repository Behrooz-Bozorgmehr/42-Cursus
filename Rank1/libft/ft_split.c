/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:38:54 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/02/20 15:42:46 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup_2(const char *s1, size_t n)
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

int	ft_words_count(char const *s, char c)
{
	int		counter;
	size_t	i;
	int		flag;

	counter = 0;
	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			flag = 0;
		else if (s[i] != c && flag == 0)
		{
			flag = 1;
			counter++;
		}	
		i++;
	}
	return (counter);
}

char	**ft_put_words(char **ptr, char *str, char c, size_t length)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < length)
	{
		while (str[j] == c && str[j] != '\0')
			j++;
		str = str + j;
		j = 0;
		while (str[j] != c && str[j] != '\0')
			j++;
		ptr[i] = ft_strndup_2(str, j);
		if (!ptr[i])
			return (NULL);
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	char	*str;
	size_t	len_ptr;

	ptr = NULL;
	if (s == NULL)
		return (ptr);
	str = (char *) s;
	len_ptr = ft_words_count(str, c);
	ptr = (char **) malloc((len_ptr + 1) * sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	ptr = ft_put_words(ptr, str, c, len_ptr);
	return (ptr);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{

	char	*string = "      split       this for   me  !       ";
			char	**expected = ((char*[6]){"split", "this", "for", "me", "!", NULL});

			char	**result = ft_split(string, ' ');
			int i = 0;
			while (i < 6) {
				printf("@%s@ :@%s@\n", result[i], *expected);
				if (strcmp(result[i], *expected)) 
					printf("no result %d\n", i);
					i++;
					expected++;
			}
}
*/
/*
char	**expected = (char*[6]){"split  ", "this", "for", "me", "!", NULL};

		char	*s = "split  ||this|for|me|||||!|";
			int		i = 0;
			char	**result = ft_split(s, '|');

			while (i < 6) {
				printf("@%s@ :@%s@\n", result[i], *expected);
				if (strcmp(result[i], *expected)) 
					printf("no result %d\n", i);v
		//		free(result[i]);
				i++;
				expected++;
			}
		//	free(result[i]);
		//	free(result);

/			char	**ex = ft_split("\0aa\0bbb", '\0');
			for (int i = 0; ex[i]; i++)
			{
				if (ex[i] != NULL)
					printf("test failed %d\n", i);
			}
/
}
*/
