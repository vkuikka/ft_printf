/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_hex_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:54:53 by vkuikka           #+#    #+#             */
/*   Updated: 2020/02/09 16:55:04 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_address(int addr, t_nums info)
{
	if (info.width_pos == 1)
		ft_putnchars(' ', info.width -
			(addr ? ft_numlen_base(addr, 16) + 2 : 3));
	ft_putstr("0x");
	if (info.precision)
	{
		ft_putnchars('0', info.precision -
			(addr ? ft_numlen_base(addr, 16) : 1));
		ft_putnbr_base(addr, 16, 1);
	}
	if (info.width_pos == -1)
		ft_putnchars(' ', info.width -
			(addr ? ft_numlen_base(addr, 16) + 2 : 3));
	if (info.width < (addr ? ft_numlen_base(addr, 16) + 2 : 3))
		info.width = (addr ? ft_numlen_base(addr, 16) + 2 : 3);
	if (info.precision - (addr ? ft_numlen_base(addr, 16) + 2 : 1) > 0)
		info.width = info.precision + 2;
	else if (!info.precision)
		info.width--;
	return (ft_abs(info.width));
}

int		ft_octal(unsigned long long nbr, t_nums info)
{
	int		len;

	len = ft_numlen_base(nbr, 8) + (info.prefix == '#' ? 1 : 0);
	if (!info.precision && !nbr)
	{
		if (info.prefix == '#')
			ft_putchar('0');
		ft_putnchars(' ', info.width);
		return (info.width + len - 1);
	}
	if (info.precision > len)
		len = info.precision;
	if (info.width_pos == 1 && info.width > len)
		ft_putnchars(info.filler, info.width - len);
	if (nbr)
		ft_putnchars('0', len - ft_numlen_base(nbr, 8));
	ft_putnbr_base(nbr, 8, 1);
	info.filler = ' ';
	if (info.width_pos == -1 && info.width > len)
		ft_putnchars(info.filler, info.width - len);
	if (info.width > len)
		len = info.width;
	return (len - (info.prefix == '#' && !nbr ? 1 : 0));
}

int		ft_hex(unsigned long long nbr, t_nums i, int lowercase)
{
	int		len;

	len = ft_numlen_base(nbr, 16);
	if (!i.precision && !nbr)
	{
		ft_putnchars(' ', i.width);
		return (i.width);
	}
	if (nbr && (i.prefix == 'x' || i.prefix == 'X') && i.filler != ' ')
		ft_printf("%c%c", '0', i.prefix);
	if (i.width_pos == 1)
		ft_putnchars(i.filler, i.width - (len + (i.prefix == 'x' ||
i.prefix == 'X' ? 2 : 0)) - (i.precision - len > 0 ? i.precision - len : 0));
	if (nbr && (i.prefix == 'x' || i.prefix == 'X') && i.filler == ' ')
		ft_printf("%c%c", '0', i.prefix);
	if (i.precision > len && (len = i.precision))
		ft_putnchars('0', i.precision - ft_numlen_base(nbr, 16));
	ft_putnbr_base(nbr, 16, lowercase);
	len = (i.prefix == 'x' || i.prefix == 'X') ? len + 2 : len;
	if (i.width_pos == -1)
		ft_putnchars(' ', i.width - (len +
		(i.precision - len > 0 ? i.precision - len : 0)));
	i.width = len > i.width ? len : i.width;
	return (nbr ? ft_abs(i.width) : 1);
}
