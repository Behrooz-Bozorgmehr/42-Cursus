/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:26:07 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/05 18:49:36 by bbozorgm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define HEXA_TABLE "0123456789abcdef"
# define FD 1

int		ft_printf(const char *format, ...);
int		ft_num_len(unsigned long long n, int base);
int		ft_fill_array(char *arr, unsigned long long n,
			int base, char format);
char	*ft_convert_num(unsigned long long n, int base, char form);
long	ft_ptr_value(char *ptr);
int		ft_flag_manager(char *ptr, char spec, char flag);
int		ft_print_ptr(char *ptr);
int		ft_print_str(char *str);
int		ft_print_char(char c);
int		ft_switch_spec(va_list args, char spec);
int		ft_switch_spec_others(va_list args, char spec);
int		ft_read_format(va_list args, const char *format);
int		ft_add_zpace(va_list args, const char *format);
#endif		/* FT_PRINTF_H */
