/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:22:16 by vkuikka           #+#    #+#             */
/*   Updated: 2020/02/21 15:17:24 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_check_precision(long double num, int precision)
{
	unsigned long long	div;
	int					i;

	i = 0;
	div = 1;
	if (!num)
		return (precision);
	while (i++ < precision)
	{
		num *= 10;
		div *= 10;
	}
	if (((unsigned long long)(num * 10) % 10) > 4)
	{
		num++;
		if ((unsigned long long)num % div == 0 || !precision)
			return (0);
	}
	return (1);
}

static int	ft_precision_float(long double num, int precision)
{
	unsigned long long	div;
	int					len;
	int					i;

	i = 0;
	div = 1;
	len = 1;
	while (i++ < precision && (num *= 10) && (div *= 10))
		if (!(unsigned long long)num && ft_check_precision(num, precision - i))
			write(1, "0", 1);
	if (((unsigned long long)(num * 10) % 10) > 4)
	{
		len = ft_numlen_base(num++, 10);
		if ((ft_numlen_base(num, 10) != len &&
			(unsigned long long)num % div == 0) || !precision)
		{
			ft_putnchars('0', precision);
			return (precision + 1);
		}
	}
	if ((unsigned long long)num)
		ft_putnbr_ull(num);
	return (precision + 1);
}

int			ft_putfloat(long double num, int precision)
{
	int			div;
	int			n;
	int			reslen;

	div = 1;
	reslen = 0;
	num *= num < 0 ? -1 : 1;
	n = num;
	if (!ft_check_precision(num, precision))
		num++;
	ft_putnbr_ull(num);
	reslen += ft_numlen_base(num, 10);
	num -= (unsigned long long)num;
	if (precision)
	{
		write(1, ".", 1);
		if (!num && (reslen += precision + 1))
			ft_putnchars('0', precision);
		else
			reslen += ft_precision_float(num, precision);
	}
	return (reslen);
}
