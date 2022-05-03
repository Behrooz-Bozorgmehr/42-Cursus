/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 19:16:50 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/03 15:24:37 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef	BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif /* BUFFER_SIZE */

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strjoin_and_free(char *s1, char *s2);
char	*ft_get_line(char *str);
size_t	ft_strlen(const char *str);
void	ft_fill(char *join, char *s1, char *s2);
char	*ft_free_left_of_n(char *stock);
char	*ft_strchr(const char *s, int c);
char	*free_ptr(char *str);

#endif	/* GET_NEXT_LINE_H */
