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

static long long			ft_signed_type(long long num, t_nums info)
{
	if (info.intsize == 0)
		return ((int)num);
	if (info.intsize == 1)
		return ((long)num);
	if (info.intsize >= 2)
		return ((long long)num);
	if (info.intsize == -1)
		return ((short)num);
	if (info.intsize <= -2)
		return ((char)num);
	return (num);
}

static unsigned long long	ft_unsigned_type(long long num, t_nums info)
{
	if (info.intsize == 0)
		return ((unsigned int)num);
	if (info.intsize == 1)
		return ((unsigned long)num);
	if (info.intsize >= 2)
		return ((unsigned long long)num);
	if (info.intsize == -1)
		return ((unsigned short)num);
	if (info.intsize <= -2)
		return ((unsigned char)num);
	return (num);
}

int							ft_nums(va_list vl, t_nums info, char arg)
{
	if (arg == 'd' || arg == 'i')
		info.width = ft_integer(ft_signed_type(va_arg(vl,
				long long), info), info);
	else if (arg == 'u')
		info.width = ft_uinteger(ft_unsigned_type(va_arg(vl,
				unsigned long long), info), info);
	else if (arg == 'f')
	{
		if (info.intsize != 100)
			info.width = ft_float(va_arg(vl, double), info);
		else if (info.intsize == 100)
			info.width = ft_float(va_arg(vl, long double), info);
	}
	return (ft_abs(info.width));
}

int							ft_chars(va_list vl, t_nums info, char arg)
{
	if (arg == 's')
		info.width = ft_string(va_arg(vl, char *), -1, info);
	else if (arg == 'c')
		info.width = ft_string(NULL, (char)va_arg(vl, int), info);
	else if (arg == 'o')
		info.width = ft_octal(ft_unsigned_type(va_arg(vl,
				unsigned long long), info), info);
	else if ((arg == 'x' || arg == 'X'))
	{
		info.prefix = info.prefix == '#' ? arg : info.prefix;
		info.width = ft_hex(ft_unsigned_type(va_arg(vl, unsigned long long),
							info), info, arg == 'x' ? 1 : 0);
	}
	else if (arg == 'p')
		info.width = ft_address((long)va_arg(vl, void *), info);
	return (ft_abs(info.width));
}

t_nums						ft_flags(char *arg, t_nums info)
{
	if (*arg == 'l')
		info.intsize++;
	else if (*arg == 'L')
		info.intsize = 100;
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
	if (*arg == '%')
		info.width = ft_percent(info);
	return (info);
}
