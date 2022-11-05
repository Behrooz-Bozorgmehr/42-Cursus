/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:20:22 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/21 11:05:13 by bbozorgm         ###   ########.fr       */
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
# define SPEC "diuoxXfFeEgGaAcspn%"
# define SPECLENT 19
# define FD 1

typedef struct s_print
{
	int		spec;
	int		dash;
	int		sign;
	int		htag;
	int		is_zero;
	int		wdt;
	int		precision;
	int		sp;
	int		point;
	int		pcent;
	int		totlen;
	int		adrs;
	va_list	args;
}	t_print;

int		ft_printf(const char *format, ...);
int		ft_eval_format(t_print *tab, const char *format, int n);
void	ft_print_val(t_print *tab, char c);
int		ft_is_spec(char c);
void	ft_convert_and_print(t_print *tab);
void	ft_fill(char *ptr, uintptr_t n, t_print *tab);
int		ft_num_len(uintptr_t n, unsigned int base );
void	ft_print_ptr(t_print *tab, char *ptr);
char	*ft_free(char *ptr);
void	ft_print_str(t_print *tab);
void	ft_print_char(t_print *tab);
void	ft_update_tab(t_print *tab, int len);
t_print	*ft_init(t_print *tab);
int		ft_left_cs(t_print *tab, int len);
int		ft_right_cs(t_print *tab, int len, char *ptr);
long	ft_ptr_value(char *ptr);
int		ft_precision(t_print *tab, int len, char *ptr);
int		ft_atoi_and_dot(const char *str);
void	ft_write_condition(t_print *tab, char *ptr, int len);
#endif		/* FT_PRINTF_H */
