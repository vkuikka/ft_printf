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

static int	ft_putfloat_float(double num, int len)
{
	int reslen;
	int	n;
	int i;

	i = 0;
	n = 0;
	reslen = 0;
	write(1, ".", 1);
	while (i < len && i < 16 && (num *= 10))
	{
		n = num + '0';
		write(1, &n, 1);
		num -= n - '0';
		reslen++;
		i++;
	}
	while (i++ < len && ++reslen)
		write(1, "0", 1);
	reslen++;
	num *= 10;
	n = num + '0';
	if (!((num - (double)(int)num) * 10 < 5))
		n++;
	return (reslen);
}

int			ft_putfloat(double num, int floats)
{
	int		div;
	int		n;
	int		reslen;

	n = num;
	div = 1;
	reslen = 0;
	while ((int)num / (div * 10))
		div *= 10;
	if (num < 0 && (num *= -1) && (++reslen))
		write(1, "-", 1);
	while (div && (n = num / div + '0'))
	{
		write(1, &n, 1);
		num -= (n - '0') * div;
		div = div == 1 ? 0 : div / 10;
		reslen++;
	}
	if (floats && (reslen++))
		reslen += ft_putfloat_float(num, floats);
	return (reslen);
}

int			ft_float_len(double num, int floats)
{
	int		div;
	int		n;
	int		reslen;

	n = num;
	div = 1;
	reslen = 0;
	while ((int)num / (div * 10))
		div *= 10;
	if (num < 0 && (num *= -1))
		reslen++;
	while (div && (n = num / div + '0'))
	{
		num -= (n - '0') * div;
		div = div == 1 ? 0 : div / 10;
		reslen++;
	}
	reslen += floats + 1;
	// ft_putnbr(reslen);
	return (reslen);
}
