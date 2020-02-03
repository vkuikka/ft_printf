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

	len = ft_unsignedlen(num);
	if (info.prefix == '+' && num)
		ft_putchar('+');
	if (info.width < 0)
		ft_putnchars(info.filler, (info.width * -1) - len);
	ft_putnbr_ull(num);
	if (info.width > 0)
		ft_putnchars(info.filler, info.width - len);
	if (info.width < 0)
		info.width *= -1;
	if (len > info.width)
		info.width = len;
	return (info.width);
}

int		ft_integer(long long num, t_nums info)
{
	int		len;

	len = ft_signedlen(num);
	if (num < 0)
	{
		info.prefix = '-';
		num *= -1;
	}
	if ((num > 0 && info.prefix == '+') || info.prefix == ' ')
		len++;
	if (info.filler != ' ' && info.prefix && num > 0)
		ft_putchar(info.prefix);
	if (info.width < 0)
		ft_putnchars(info.filler, (info.width * -1) - len);
	if (info.filler == ' ' && (info.prefix == '+' || info.prefix == '-' || info.prefix == ' ') && num > 0)
		ft_putchar(info.prefix);
	ft_putnbr_ll(num);
	if (info.width > 0)
		ft_putnchars(info.filler, info.width - len);
	if (info.width < 0)
		info.width *= -1;
	if (len > info.width)
		info.width = len;
	return (info.width);
}

int		ft_float(double num, t_nums info)
{
	int		len;

	if (info.precision == -1)
		info.precision = 6;
	len = ft_float_len(num, info.prefix ? 1 : 0, info.precision);
	if (num < 0)
	{
		// if (width < 0)
		// 	width--;
		// else if (prefix)
		// 	width++;
		if (info.filler == '0')
		{
			ft_putchar('-');
			num *= -1;
		}
	}
	if (info.filler != ' ' && info.prefix && num > 0)
		ft_putchar(info.prefix);
	if (info.width < 0)
		ft_putnchars(info.filler, (info.width * -1) - len);
	if (info.filler == ' ' && info.prefix && num > 0)
		ft_putchar(info.prefix);
	ft_putfloat(num, info.prefix ? 1 : 0, info.precision);
	if (info.width > 0)
		ft_putnchars(info.filler, info.width - len);
	if (info.width < 0)
		info.width *= -1;
	if (len > info.width)
		info.width = len;
	return (info.width);
}

int		ft_chars(char *s, char c, t_nums info)
{
	int		len;

	len = 1;
	if (!s && !c)
	{
		ft_putstr("(null)");
		return (6);
	}
	if (s)
		len = ft_strlen(s);
	if ((info.prefix == 'x' || info.prefix == 'X') && ((s && s[0] != '0') || (!s && c != '0')))
		len += 2;
	if ((info.prefix == 'x' || info.prefix == 'X') && info.filler != ' ' && ((s && s[0] != '0') || (!s && c != '0')))
	{
		ft_putchar('0');
		ft_putchar(info.prefix);
	}
	if (info.width < 0)
		ft_putnchars(info.filler, info.width * -1 - len);
	if ((info.prefix == 'x' || info.prefix == 'X') && info.filler == ' ' && ((s && s[0] != '0') || (!s && c != '0')))
	{
		ft_putchar('0');
		ft_putchar(info.prefix);
	}
	if ((size_t)info.precision > ft_numlen_base(ft_atoi_base(s, 16), 16))
		ft_putnchars('0', (size_t)info.precision - ft_numlen_base(ft_atoi_base(s, 16), 16));
	if (s)
		ft_putstr_len(s, info.precision);
	else
		ft_putchar(c);
	if (info.prefix == 'X' || info.prefix == 'x')
		info.filler = ' ';
	if (info.width > 0)
		ft_putnchars(info.filler, info.width - len);
	if (info.width < 0)
		info.width *= -1;
	if (len > info.width)
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
