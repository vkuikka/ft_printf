/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:40:36 by vkuikka           #+#    #+#             */
/*   Updated: 2020/02/09 16:40:37 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int	ft_signed_int(t_nums info, va_list vl)
{
	if (info.intsize == 0)
		info.width = ft_integer(va_arg(vl, int), info);
	else if (info.intsize == 1)
		info.width = ft_integer(va_arg(vl, long), info);
	else if (info.intsize >= 2)
		info.width = ft_integer(va_arg(vl, long long), info);
	else if (info.intsize == -1)
		info.width = ft_integer((short)va_arg(vl, int), info);
	else if (info.intsize <= -2)
		info.width = ft_integer((char)va_arg(vl, int), info);
	return (info.width);
}

int			ft_nums(va_list vl, t_nums info, char arg)
{
	if (arg == 'd' || arg == 'i')
		return (ft_signed_int(info, vl));
	else if (arg == 'u')
	{
		if (info.intsize == 0)
			info.width = ft_uinteger(va_arg(vl, unsigned int), info);
		else if (info.intsize == 1)
			info.width = ft_uinteger(va_arg(vl, unsigned long), info);
		else if (info.intsize >= 2)
			info.width = ft_uinteger(va_arg(vl, unsigned long long), info);
		else if (info.intsize == -1)
			info.width = ft_uinteger((unsigned short)va_arg(vl, unsigned int),
						info);
		else if (info.intsize <= -2)
			info.width = ft_uinteger((unsigned int)va_arg(vl, unsigned int),
						info);
	}
	else if (arg == 'f' || arg == 'L')
	{
		if (info.intsize == 0)
			info.width = ft_float(va_arg(vl, double), info);
		if (info.intsize >= 1)
			info.width = ft_float(va_arg(vl, long double), info);
	}
	return (ft_abs(info.width));
}

static int	ft_hexadecimal(va_list vl, t_nums info, char arg)
{
	int		lowercase;

	lowercase = arg == 'x' ? 1 : 0;
	if (info.prefix == '#')
		info.prefix = arg;
	if (info.intsize == 0)
		info.width = ft_hex(va_arg(vl, unsigned int), info, lowercase);
	else if (info.intsize == 1)
		info.width = ft_hex(va_arg(vl, unsigned long), info, lowercase);
	else if (info.intsize >= 2)
		info.width = ft_hex(va_arg(vl, unsigned long long), info, lowercase);
	else if (info.intsize == -1)
		info.width = ft_hex((unsigned short)va_arg(vl, unsigned int), info,
		lowercase);
	else if (info.intsize <= -2)
		info.width = ft_hex((unsigned char)va_arg(vl, unsigned int), info,
		lowercase);
	return (info.width);
}

int			ft_chars(va_list vl, t_nums info, char arg)
{
	if (arg == 's' && !(info.valid = 0))
		info.width = ft_string(va_arg(vl, char *), -1, info);
	else if (arg == 'c' && !(info.valid = 0))
		info.width = ft_string(NULL, (char)va_arg(vl, int), info);
	else if (arg == 'o' && !(info.valid = 0))
		info.width = ft_octal(va_arg(vl, unsigned long long), info);
	else if ((arg == 'x' || arg == 'X') && !(info.valid = 0))
		return (ft_hexadecimal(vl, info, arg));
	else if (arg == 'p' && !(info.valid = 0))
	{
		if (info.width < 0)
			ft_putnchars(' ', info.width * -1 - 14);
		ft_putstr("0x");
		ft_putaddr((va_arg(vl, void *)));
		if (info.width > 0)
			ft_putnchars(' ', info.width - 14);
		if (info.width > 0)
			info.width += 14;
		else
			info.width = 14;
	}
	return (ft_abs(info.width));
}

t_nums		ft_flags(char *arg, t_nums info)
{
	if (*arg == 'l')
		info.intsize++;
	else if (*arg == 'h')
		info.intsize--;
	else if (*arg == '.' && arg++)
	{
		info.precision = ft_atoi(arg);
		arg += ft_unsignedlen(info.precision) - 1;
	}
	else if (*arg == '-')
		info.width_pos = -1;
	else if (*arg == '+' || *arg == '#' || (*arg == ' ' && info.prefix != '+'))
		info.prefix = *arg;
	if ((*arg == '%') && !(info.valid = 0))
		info.width = ft_percent(info);
	return (info);
}
