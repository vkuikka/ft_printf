/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_handling.c                                  :+:      :+:    :+:   */
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
	len = !num && !info.precision ? 0 : len;
	info.prefix = info.prefix == '#' ? 0 : info.prefix;
	info.filler = info.precision > 0 ? ' ' : info.filler;
	if (info.filler != ' ' && info.prefix)
		ft_putchar(info.prefix);
	if (info.width_pos == 1)
		ft_putnchars(info.filler, info.width -
		(info.precision > len ? info.precision : len) - !!(info.prefix));
	if (info.filler == ' ' && info.prefix)
		ft_putchar(info.prefix);
	info.prefix = (info.width_pos == 1 && info.prefix == ' ' &&
		info.width > info.precision && info.width > len) ? 0 : info.prefix;
	if (info.precision > len)
		ft_putnchars('0', info.precision - len);
	if (num || (info.precision && !num))
		ft_putnbr_ull(num);
	len = info.precision > len ? info.precision : len;
	if (info.width_pos == -1)
		ft_putnchars(' ', info.width - len - !!(info.prefix));
	return ((len + !!(info.prefix)) < info.width ?
			info.width : (len + !!(info.prefix)));
}

int		ft_integer(long long num, t_nums info)
{
	int		len;

	len = ft_unsignedlen(num < 0 ? num * -1 : num);
	len = !num && !info.precision ? 0 : len;
	info.prefix = info.prefix == '#' ? 0 : info.prefix;
	num *= num < 0 && (info.prefix = '-') ? -1 : 1;
	info.filler = info.precision > 0 ? ' ' : info.filler;
	if (info.filler != ' ' && info.prefix)
		ft_putchar(info.prefix);
	if (info.width_pos == 1)
		ft_putnchars(info.filler, info.width -
		(info.precision > len ? info.precision : len) - !!(info.prefix));
	if (info.filler == ' ' && info.prefix)
		ft_putchar(info.prefix);
	info.prefix = (info.width_pos == 1 && info.prefix == ' ' &&
		info.width > info.precision && info.width > len) ? 0 : info.prefix;
	if (info.precision > len)
		ft_putnchars('0', info.precision - len);
	if (num || (info.precision && !num))
		ft_putnbr_ull(num);
	len = info.precision > len ? info.precision : len;
	if (info.width_pos == -1)
		ft_putnchars(' ', info.width - len - !!(info.prefix));
	return ((len + !!(info.prefix)) < info.width ?
			info.width : (len + !!(info.prefix)));
}

int		ft_float(long double num, t_nums info)
{
	int		len;
	int		n;

	n = 0;
	len = 0;
	if (info.precision == -1)
		info.precision = 6;
	if ((num > 0 && info.prefix == '+') || info.prefix == ' ' || num < 0)
		len++;
	if (num < 0)
	{
		n = 1;
		num *= -1;
	}
	if (info.filler != ' ' && info.prefix && info.prefix != '#')
		ft_putchar(info.prefix);
	if (info.width_pos == 1)
		ft_putnchars(info.filler, info.width - len);
	if (info.filler == ' ' && info.prefix && info.prefix != '#')
		ft_putchar(info.prefix);
	len += ft_putfloat(num, info.precision, n);
	if (!info.precision && info.prefix == '#' && ++len)
		ft_putchar('.');
	if (info.width_pos == -1)
		ft_putnchars(' ', info.width - len);
	if (len < ft_abs(info.width))
		len = info.width;
	return (len);
}

int		ft_string(char *s, char c, t_nums info)
{
	int		len;

	if (!s && c == -1)
		s = "(null)";
	len = s ? ft_strlen(s) : 1;
	if (s && s[0] == '\0')
		ft_putnchars(info.filler, info.width);
	if (!s && c == -1)
		len = 6;
	if (info.precision > -1 && info.precision < len)
		len = info.precision;
	if (info.width_pos == 1)
		ft_putnchars(info.filler, info.width - len);
	if (s)
		ft_putstr_len(s, len);
	else if (c != -1)
		ft_putchar(c);
	if (info.width_pos == -1)
		ft_putnchars(' ', info.width - len);
	if (len < info.width)
		len = info.width;
	return (c == 0 && !len ? 1 : len);
}

int		ft_percent(t_nums info)
{
	int		len;

	len = 1;
	if (info.width_pos == 1)
		ft_putnchars(info.filler, info.width - len);
	ft_putchar('%');
	if (info.width_pos == -1)
		ft_putnchars(' ', info.width - len);
	return (info.width ? info.width : 1);
}
