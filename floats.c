/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floats.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 16:22:16 by vkuikka           #+#    #+#             */
/*   Updated: 2020/02/06 19:27:43 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


#include <stdio.h>


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
	if (precision)
		write(1, ".", 1);
	if (!num)
	{
		ft_putnchars('0', precision);
		return (precision + 1);
	}
	while (i++ < precision)
	{
		num *= 10;
		if (!(unsigned long long)num && ft_check_precision(num, precision - i))
			write(1, "0", 1);
		div *= 10;
	}
	if (((unsigned long long)(num * 10) % 10) > 4)
	{
		len = ft_numlen_base(num, 10);
		num++;
		if ((ft_numlen_base(num, 10) != len && (unsigned long long)num % div == 0) || !precision)
		{
			ft_putnchars('0', precision);
			return (precision + 1);
		}
	}
	if ((unsigned long long)num)
		ft_putnbr_ull(num);
	return (precision + 1);
}

int			ft_putfloat(long double num, int precision, int negative)
{
	int			div;
	int			n;
	int			reslen;

	n = num;
	div = 1;
	reslen = 0;
	if (negative)
		ft_putchar('-');
	if (!ft_check_precision(num, precision))
		num++;
	ft_putnbr_ull(num);
	reslen += ft_numlen_base(num, 10);
	num -= (unsigned long long)num;
	if (precision)
		reslen += ft_precision_float(num, precision);
	return (reslen);
}
