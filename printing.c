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

int		ft_uinteger(unsigned long long num, int plus, int width, char filler)
{
	int		len;

	len = ft_unsignedlen(num);
	if (plus && num)
		ft_putchar('+');
	if (width < 0)
		ft_putnchars(filler, (width * -1) - len);
	ft_putnbr_ull(num);
	if (width > 0)
		ft_putnchars(filler, width - len);
	if (width < 0)
		width *= -1;
	if (len > width)
		width = len;
	return (width);
}

int		ft_integer(long long num, char prefix, int width, char fill)
{
	int		len;

	len = ft_signedlen(num);
	if (num < 0)
	{
		prefix = '-';
		num *= -1;
	}
	if ((num > 0 && prefix == '+') || prefix == ' ')
		len++;
	if (fill != ' ' && prefix && num > 0)
		ft_putchar(prefix);
	if (width < 0)
		ft_putnchars(fill, (width * -1) - len);
	if (fill == ' ' && (prefix == '+' || prefix == '-' || prefix == ' ') && num > 0)
		ft_putchar(prefix);
	ft_putnbr_ll(num);
	if (width > 0)
		ft_putnchars(fill, width - len);
	if (width < 0)
		width *= -1;
	if (len > width)
		width = len;
	return (width);
}

int		ft_float(double num, char prefix, int width, char fill, int floats)
{
	int		len;

	if (floats == -1)
		floats = 6;
	len = ft_float_len(num, prefix ? 1 : 0, floats);
	if (num < 0)
	{
		// if (width < 0)
		// 	width--;
		// else if (prefix)
		// 	width++;
		if (fill == '0')
		{
			ft_putchar('-');
			num *= -1;
		}
	}
	if (fill != ' ' && prefix && num > 0)
		ft_putchar(prefix);
	if (width < 0)
		ft_putnchars(fill, (width * -1) - len);
	if (fill == ' ' && prefix && num > 0)
		ft_putchar(prefix);
	ft_putfloat(num, prefix ? 1 : 0, floats);
	if (width > 0)
		ft_putnchars(fill, width - len);
	if (width < 0)
		width *= -1;
	if (len > width)
		width = len;
	return (width);
}

int		ft_chars(char *s, char c, int width, char prefix, char filler, int precision)
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
	if ((prefix == 'x' || prefix == 'X') && ((s && s[0] != '0') || (!s && c != '0')))
		len += 2;
	if ((prefix == 'x' || prefix == 'X') && filler != ' ' && ((s && s[0] != '0') || (!s && c != '0')))
	{
		ft_putchar('0');
		ft_putchar(prefix);
	}
	if (width < 0)
		ft_putnchars(filler, width * -1 - len);
	if ((prefix == 'x' || prefix == 'X') && filler == ' ' && ((s && s[0] != '0') || (!s && c != '0')))
	{
		ft_putchar('0');
		ft_putchar(prefix);
	}
	if ((size_t)precision > ft_numlen_base(ft_atoi_base(s, 16), 16))
		ft_putnchars('0', (size_t)precision - ft_numlen_base(ft_atoi_base(s, 16), 16));
	if (s)
		ft_putstr_len(s, precision);
	else
		ft_putchar(c);
	if (prefix == 'X' || prefix == 'x')
		filler = ' ';
	if (width > 0)
		ft_putnchars(filler, width - len);
	if (width < 0)
		width *= -1;
	if (len > width)
		width = len;
	return (width);
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
