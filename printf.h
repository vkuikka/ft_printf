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
# include <stdarg.h>	//remove from ft_printf.c
# include "libft.h"

typedef struct	s_nums
{
	int			precision;
	int			width;
	int			valid;
	int			intsize;
	char		filler;
	char		prefix;
}				t_nums;

void	ft_putaddr(void *ptr);

int		ft_printf(char *arg, ...);
int		ft_float_len(double num, int mark, int floats);
int		ft_putfloat(double num, int mark, int floats);
void	ft_putnbr_ll(long long num);
void	ft_putnbr_ull(unsigned long long num);

void	ft_putnchars(char c, int amount);
void	ft_putstr_len(char *str, size_t len);
int		ft_unsignedlen(unsigned long long num);
int		ft_signedlen(long long num);
size_t	ft_numlen_base(long nb, int base);

int		ft_uinteger(unsigned long long num, t_nums info);
int		ft_integer(long long num, t_nums info);
int		ft_float(double num, t_nums info);
int		ft_strings(char *s, char c, t_nums info);

int		ft_percent(int width, char filler);

#endif
