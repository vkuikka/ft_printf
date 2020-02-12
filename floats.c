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
	int					len;
	int					i;

	i = 0;
	div = 1;
	while (i++ < precision)
	{
		num *= 10;
		div *= 10;
	}
	if (((unsigned long long)(num * 10) % 10) > 4)
	{
		len = ft_numlen_base(num, 10);
		num++;
		if ((unsigned long long)num % div == 0 || !precision)
			return (0);
	}
	return (1);
}

static int	ft_putprec_float(long double num, int precision)
{
	unsigned long long	div;
	int					reslen;
	int					i;

	i = 0;
	div = 1;
	reslen = 1;
	write(1, ".", 1);
	while (i++ < precision)
	{
		num *= 10;
		div *= 10;
	}
	if (((unsigned long long)(num * 10) % 10) > 4)
	{
		reslen = ft_numlen_base(num, 10);
		num++;
		if ((ft_numlen_base(num, 10) != reslen && (unsigned long long)num % div == 0) || !precision)
		{
			ft_putnchars('0', precision);
			return (precision);
		}
	}
	ft_putnbr_ull(num);
	return (reslen);
}

int			ft_putfloat(long double num, int precision)
{
	int			div;
	int			n;
	int			reslen;

	n = num;
	div = 1;
	reslen = 0;
	if (precision && !ft_check_precision(num, precision))
		num++;
	ft_putnbr_ull(num);
	reslen += ft_numlen_base(num, 10);
	num -= (unsigned long long)num;
	reslen += ft_putprec_float(num, precision);
	return (reslen);
}

int			ft_float_len(long double num, int floats)
{
	long double		cp;
	int				n;
	int				reslen;

	n = num;
	cp = num;
	if (num < 0)
		num *= -1;
	reslen = num < 1 ? 1 : 0;
	while ((int)cp)
	{
		cp /= 10;
		reslen++;
	}
	while (num && floats)
	{
		num -= (long long)num;
		num *= 10;
		reslen++;
		floats--;
	}
	return (reslen);
}
