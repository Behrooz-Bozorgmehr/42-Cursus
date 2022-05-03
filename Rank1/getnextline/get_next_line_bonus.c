/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:42:40 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/03 15:36:05 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_line(char *store, int fd)
{
	char	*buf;
	int		ret;

	ret = 1;
	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buf == NULL)
		return (NULL);
	while (ret && ft_strchr(store, '\n') == NULL)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1 )
			return (free_ptr(buf));
		buf[ret] = '\0';
		store = ft_strjoin_and_free(store, buf);
	}
	free_ptr(buf);
	return (store);
}

char	*ft_get_line(char *str)
{
	char	*line;
	size_t	i;

	line = NULL;
	i = 0;
	if (str[0] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	line = (char *) malloc(sizeof(char) * (i + 2));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_free_left_of_n(char *stock)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	if (stock[i] == '\0')
	{
		free(stock);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(stock) - i + 1));
	if (str == NULL)
		return (NULL);
	while (stock[i])
		str[j++] = stock[++i];
	str[j] = '\0';
	free(stock);
	return (str);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*store[1024];	

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (NULL);
	store[fd] = ft_read_line(store[fd], fd);
	if (store[fd] == NULL)
		return (NULL);
	line = ft_get_line(store[fd]);
	store[fd] = ft_free_left_of_n(store[fd]);
	return (line);
}
