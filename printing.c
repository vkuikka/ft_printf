/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:50:22 by vkuikka           #+#    #+#             */
/*   Updated: 2020/01/30 13:27:32 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_uinteger(unsigned long long num, t_nums info)
{
	int		len;

	len = ft_unsignedlen(num) < info.precision ? info.precision : ft_unsignedlen(num);
	if (info.intsize == -1)
		num = (unsigned short)num;
	else if (info.intsize <= -2)
		num = (unsigned char)num;
	else if (info.intsize == 0)
		num = (unsigned int)num;
	else if (info.intsize == 1)
		num = (unsigned long)num;
	else if (info.intsize >= 2)
		num = (unsigned long long)num;
	if ((info.prefix == '+' || info.prefix == ' ') && num)
		ft_putchar(info.prefix);
	if (info.width < 0)
		ft_putnchars(info.filler, (info.width * -1) - len);
	if (info.precision > ft_unsignedlen(num))
		ft_putnchars('0', info.precision - ft_unsignedlen(num));
	ft_putnbr_ull(num);
	if (info.width > 0)
		ft_putnchars(info.filler, info.width - len);
	if (len > ft_abs(info.width))
		info.width = len;
	return (info.width);
}

int		ft_integer(long long num, t_nums info)
{
	int		len;

	len = ft_signedlen(num) < info.precision ? info.precision : ft_signedlen(num);

	if (info.intsize == -1)
		num = (short)num;
	else if (info.intsize <= -2)
		num = (signed char)num;
	else if (info.intsize == 0)
		num = (int)num;
	else if (info.intsize == 1)
		num = (long)num;
	else if (info.intsize >= 2)
		num = (long long)num;
	if (num < 0)
	{
		info.prefix = '-';
		num *= -1;
	}
	if ((num > 0 && info.prefix == '+') || info.prefix == ' ')
		len++;

	if (info.filler != ' ' && info.prefix && info.prefix != '#')
		ft_putchar(info.prefix);
	if (info.width < 0)
		ft_putnchars(info.filler, (info.width * -1) - len);
	if (info.filler == ' ' && info.prefix && info.prefix != '#')
		ft_putchar(info.prefix);
	if (info.precision > ft_signedlen(num))
		ft_putnchars('0', info.precision - ft_signedlen(num));
	if (!info.precision && !num)
		ft_putnchars(' ', ft_numlen_base(num, 10));
	else
		ft_putnbr_ll(num);
	if (info.width > 0)
		ft_putnchars(info.filler, info.width - len);
	if (len > ft_abs(info.width))
		info.width = len;
	return (info.width);
}

int		ft_float(double num, t_nums info)
{
	int		len;

	if (info.precision == -1)
		info.precision = 6;
	len = ft_float_len(num, info.precision);
	if (num < 0)
	{
		info.prefix = '-';
		num *= -1;
	}
	if ((num > 0 && info.prefix == '+') || info.prefix == ' ')
		len++;

	if (info.filler != ' ' && info.prefix && info.prefix != '#')
		ft_putchar(info.prefix);
	if (info.width < 0)
		ft_putnchars(info.filler, (info.width * -1) - len);
	if (info.filler == ' ' && info.prefix && info.prefix != '#')
		ft_putchar(info.prefix);
	ft_putfloat(num, info.precision);

	if (info.width > 0)
		ft_putnchars(info.filler, info.width - len);

	if (len > ft_abs(info.width))
		info.width = len;
	return (info.width);
}

int		ft_string(char *s, char c, t_nums info)
{
	int		len;

	len = s ? ft_strlen(s) : 1;
	if (!s && !c)
	{
		ft_putstr("(null)");
		return (6);
	}

	if ((s && info.width - ft_strlen(s) < 0) || (!s && info.width < -1))
		ft_putnchars(info.filler, info.width * -1 - len);
	if (s && (size_t)info.precision > ft_numlen_base(ft_atoi_base(s, 16), 16))
		ft_putnchars(' ', (size_t)info.precision - ft_numlen_base(ft_atoi_base(s, 16), 16));

	if (s)
		ft_putstr_len(s, info.precision);
	else
		ft_putchar(c);

	if (info.width > 0)
		ft_putnchars(info.filler, info.width - len);
	if (len > ft_abs(info.width))
		info.width = len;
	return (info.width);
}

int		ft_percent(int width, char filler)
{
	int		len;

	len = 1;
	if (width < 0)
		ft_putnchars(filler, (width * -1) - len);
	ft_putchar('%');
	if (width > 0)
		ft_putnchars(filler, width - len);
	if (width < 0)
		width *= -1;
	if (width)
		return (width);
	return (1);
}
