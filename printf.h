/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 22:06:27 by vkuikka           #+#    #+#             */
/*   Updated: 2020/01/27 17:59:35 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "libft.h"

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

int		ft_uinteger(unsigned long long num, int plus, int width, char filler);
int		ft_integer(long long num, char prefix, int width, char fill);
int		ft_float(double num, char prefix, int width, char fill, int floats);
int		ft_chars(char *s, char c, int width, char prefix, char filler, int precision);
int		ft_percent(int width, char filler);

#endif
