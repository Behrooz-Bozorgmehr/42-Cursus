/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbozorgm <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/07 10:20:22 by bbozorgm          #+#    #+#             */
/*   Updated: 2022/05/07 14:38:39 by bbozorgm         ###   ########.fr       */
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
# define CHAR va_arg(args, int)
# define STRG va_arg(args, (char *))
# define PTR va_args(args, unsigned long long)
# define USGN va_args(args, unsigned int)
# define UHEX va_args(args, unsigned int)
# define LHEX va_args(args, unsigned int)
# define OCT va_args(args, unsigned int)
# define INT va_args(args, int)
# define DECI va_args(args, int)
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
	va_list	args;
   
}	t_print;

int 	ft_printf(const char *format, ...);
int		ft_eval_format(t_print *tab, const char *format, int i);
void	ft_print_val(t_print *tab, char c);
int		ft_is_spec(char c);
void	ft_convert_and_print(t_print *tab);
void	ft_fill(char *ptr, unsigned long long n, t_print *tab, char spec);
int		ft_num_len(unsigned long long n, int base );
void	ft_print_ptr(t_print *tab, char *ptr);
char	*ft_free(char *ptr);
void	ft_print_str(t_print *tab);
void	ft_print_char(t_print *tab);
void	ft_update_tab(t_print *tab, int i);
t_print *ft_init(t_print *tab);

#endif		/* FT_PRINTF_H */
