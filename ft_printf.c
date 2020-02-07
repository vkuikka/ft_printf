/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:19:39 by vkuikka           #+#    #+#             */
/*   Updated: 2020/01/28 16:19:43 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


#include <stdarg.h>
#include "libft/includes/libft.h"


size_t	ft_digit_count(long nb, int base)
{
	size_t		i;

	i = 1;
	while (nb /= base)
		i++;
	return (i);
}

int		ft_strlen_limit(char *str, char delimiter)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != delimiter)
		i++;
	return (i);
}

char	*ft_skiparg(char *arg)
{
	while (*arg != 'd' && *arg != 'i' && *arg != 'o' && *arg != 'u' && *arg != 'f' &&
		*arg != 'x' && *arg != 'X' && *arg != 'c' && *arg != 's' && *arg != 'p' && *arg != '%')
		arg++;
	return (arg);
}

int		ft_octal(char *nbr, t_nums info)
{
	int		len;
	int		ret;

	len = ft_strlen(nbr) + (info.precision - (int)ft_strlen(nbr) > 0 ? info.precision - ft_strlen(nbr) : 0);
	ret = info.precision > info.width ? info.precision : info.width;
	ret = ft_strlen(nbr) > (size_t)ft_abs(ret) ? ft_strlen(nbr) : ret;

	// if (info.prefix == '#' && !info.precision)
	// 	len++;
	if (!info.precision)
	{
		ft_putnchars(' ', ft_abs(info.width));
		return (ft_abs(info.width));
	}
	if (info.width < 0)
		ft_putnchars(info.filler, info.width * -1 - len);
	if (info.prefix == '#')
		ft_putchar('0');
	ft_putnchars('0', info.precision - ft_strlen(nbr));
	if (info.width < 0)
		len += info.width * -1;
	ft_putstr(nbr);
	if (info.width > 0)
		ft_putnchars(info.filler, info.width - len);
	if (len > ft_abs(info.width))
		info.width = len;
	return (ret);
}

int		ft_hex(char *nbr, t_nums info)
{
	int		len;

	len = ft_strlen(nbr);
	if (!info.precision)
	{
		ft_putnchars(' ', ft_abs(info.width));
		return (ft_abs(info.width));
	}
	if (nbr[0] != '0' && (info.prefix == 'x' || info.prefix == 'X') && info.filler != ' ')
	{
		ft_putchar('0');
		ft_putchar(info.prefix);
	}
	if ((info.prefix == 'x' || info.prefix == 'X') && info.width < 0)
		ft_putnchars(info.filler, info.width * -1 - ((len + 2) + (info.precision - len > 0 ? info.precision - len : 0)));
	else if (info.width < 0)
		ft_putnchars(info.filler, info.width * -1 - (len + (info.precision - len > 0 ? info.precision - len : 0)));
	if (nbr[0] != '0' && (info.prefix == 'x' || info.prefix == 'X') && info.filler == ' ')
	{
		ft_putchar('0');
		ft_putchar(info.prefix);
	}
	if (info.precision > len)
	{
		ft_putnchars('0', info.precision - len);
		len += info.precision - len;
	}
	ft_putstr(nbr);
	if (info.prefix == 'x' || info.prefix == 'X')
		len += 2;
	if (info.width > 0)
		ft_putnchars(' ', info.width - (len + (info.precision - len > 0 ? info.precision - len : 0)));
	if (len > ft_abs(info.width))
		info.width = len;
	if (nbr[0] == '0' && nbr[1] == '\0')
		info.width = 1;
	return (ft_abs(info.width));
}

int		ft_nums(va_list vl, t_nums info, char arg)
{
	if (arg == 'd' || arg == 'i')
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
	}
	else if (arg == 'u')
	{
		if (info.intsize == 0)
			info.width = ft_uinteger(va_arg(vl, unsigned int), info);
		else if (info.intsize == 1)
			info.width = ft_uinteger(va_arg(vl, unsigned long), info);
		else if (info.intsize >= 2)
			info.width = ft_uinteger(va_arg(vl, unsigned long long), info);
		else if (info.intsize == -1)
			info.width = ft_uinteger((unsigned short)va_arg(vl, unsigned int), info);
		else if (info.intsize <= -2)
			info.width = ft_uinteger((unsigned int)va_arg(vl, unsigned int), info);
	}
	else if (arg == 'f' || arg == 'L')
		info.width = ft_float(va_arg(vl, double), info);
	return (ft_abs(info.width));
}

int		ft_chars(va_list vl, t_nums info, char arg)
{
	if (arg == 's' && !(info.valid = 0))
		info.width = ft_string(va_arg(vl, char *), 0, info);
	else if (arg == 'c' && !(info.valid = 0))
		info.width = ft_string(NULL, (char)va_arg(vl, int), info);

	else if (arg == 'o' && !(info.valid = 0))
		info.width = ft_octal(ft_itoa_base(va_arg(vl, unsigned long long), 8, 1), info);
	else if ((arg == 'x' || arg == 'X') && !(info.valid = 0))
	{
		if (info.prefix == '#')
			info.prefix = arg;
		if (info.intsize == 0)
			info.width = ft_hex(ft_itoa_base(va_arg(vl, unsigned int), 16, arg == 'x' ? 1 : 0), info);
		else if (info.intsize == 1)
			info.width = ft_hex(ft_itoa_base(va_arg(vl, unsigned long), 16, arg == 'x' ? 1 : 0), info);
		else if (info.intsize >= 2)
			info.width = ft_hex(ft_itoa_base(va_arg(vl, unsigned long long), 16, arg == 'x' ? 1 : 0), info);
		else if (info.intsize == -1)
			info.width = ft_hex(ft_itoa_base((unsigned short)va_arg(vl, unsigned int), 16, arg == 'x' ? 1 : 0), info);
		else if (info.intsize <= -2)
			info.width = ft_hex(ft_itoa_base((unsigned char)va_arg(vl, unsigned int), 16, arg == 'x' ? 1 : 0), info);
	}
	else if (arg == 'p' && !(info.valid = 0))
	{
		if (info.width < 0)
			ft_putnchars(' ', info.width * -1 - 14);
		ft_putstr("0x");
		ft_putaddr((va_arg(vl, void *)));
		if (info.width > 0)
			ft_putnchars(' ', info.width - 14);
		if (info.width  > 0)
			info.width += 14;
		else
			info.width = 14;
	}
	return (ft_abs(info.width));
}

t_nums	ft_flags(char *arg, t_nums info)
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
		info.width = 1;
	else if (*arg == '+' || *arg == '#' || *arg == ' ')
		info.prefix = *arg;
	if ((*arg == '%') && !(info.valid = 0))
		info.width = ft_percent(info.width, info.filler);
	return (info);
}

int		ft_printarg(char *arg, va_list vl)
{
	t_nums	info;

	info.precision = -1;
	info.filler = ' ';
	info.prefix = 0;
	info.width = -1;
	info.valid = 1;
	info.intsize = 0;

	int i = 0;
	while (info.valid)
	{
		i++;
		if (i > 100)
		{
			ft_putstr("error");
			exit(1);
		}

		if (*arg == '0' && (info.filler = '0'))
			arg++;
		if (ft_isdigit(*arg) && info.precision == -1)
		{
			info.width = ft_atoi(arg) * (info.width == -1 ? -1 : 1);
			while (ft_isdigit(*arg))
				arg++;
		}
		if ((*arg == 'd' || *arg == 'i' || *arg == 'u' || *arg == 'f' || *arg == 'L') && !(info.valid = 0))
			info.width = ft_nums(vl, info, *arg);
		else if ((*arg == 's' || *arg == 'c' || *arg == 'o' || *arg == 'x' || *arg == 'X' || *arg == 'p') && !(info.valid = 0))
			info.width = ft_chars(vl, info, *arg);
		else
			info = ft_flags(arg, info);
		if (info.valid)
			arg++;
	}
	return (info.width);
}

int		ft_printf(char *arg, ...)
{
	va_list		vl;
	int			len;

	len = 0;
	va_start(vl, arg);
	while (*arg)
	{
		if (*arg == '%' && *(arg++))
		{
			len += ft_printarg(arg, vl);
			arg = ft_skiparg(arg);
		}
		else
		{
			write(1, &*arg, 1);
			len++;
		}
		arg++;
	}
	va_end(vl);
	return (len);
}
