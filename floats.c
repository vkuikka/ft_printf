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

static int	ft_putfloat_float(long double num, int len)
{
	char	n;
	int		reslen;
	int		i;

	i = 0;
	n = 0;
	reslen = 1;
	write(1, ".", 1);
	while (i < len && i < 16)
	{
		num *= 10;
		if ((long double)(int)num != num)
			n = (int)(num + 0.1);
		else
			n = (int)num;
		if (((unsigned long)num * 10 % 10) > 5)
			n++;
		ft_putchar(n + '0');
		num -= n;
		reslen++;
		i++;
	}
	while (i++ < len && ++reslen)
		write(1, "0", 1);
	return (reslen);
}

int			ft_putfloat(long double num, int floats)
{
	long double	cp;
	int			div;
	int			n;
	int			reslen;

	n = num;
	div = 1;
	reslen = 0;
	cp = num;
	while ((int)cp)
		cp /= 10;
	ft_putnbr_ull(num);
	reslen = ft_numlen_base(num, 10);
	num -= (unsigned long long)num;
	if (floats && (reslen++))
		reslen += ft_putfloat_float(num, floats);
	reslen--;
	return (reslen);
}

int			ft_float_len(long double num, int floats)
{
	long double		cp;
	int				n;
	int				reslen;

	n = num;
	cp = num;
	reslen = 0;
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
