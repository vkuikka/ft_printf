/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 22:06:27 by vkuikka           #+#    #+#             */
/*   Updated: 2020/02/03 18:21:19 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include "libft.h"

typedef struct	s_nums
{
	int			intsize;
	int			precision;
	int			width_pos;
	int			width;
	int			valid;
	char		filler;
	char		prefix;
}				t_nums;

int				ft_printf(char *arg, ...);

/*
**	PRINTING
*/
void			ft_putstr_len(char *str, size_t len);
void			ft_putnchars(char c, int amount);
void			ft_putnbr_ull(unsigned long long num);
int				ft_putfloat(long double num, int floats);

/*
**	LENGTH
*/
int				ft_numlen_base(unsigned long long nb, int base);
int				ft_unsignedlen(unsigned long long num);
int				ft_float_len(long double num, int floats);

/*
**	OUTPUT HANDLING
*/
int				ft_float(long double num, t_nums info);
int				ft_integer(long long num, t_nums info);
int				ft_uinteger(unsigned long long num, t_nums info);
int				ft_string(char *s, long long c, t_nums info);
int				ft_octal(unsigned long long nbr, t_nums info);
int				ft_hex(unsigned long long nbr, t_nums info, int lowercase);
int				ft_percent(t_nums info);
int				ft_address(long addr, t_nums info);

/*
**	FUNCTION INPUT HANDLING
*/
int				ft_chars(va_list vl, t_nums info, char arg);
int				ft_nums(va_list vl, t_nums info, char arg);
t_nums			ft_flags(char *arg, t_nums info);

#endif
