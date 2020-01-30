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

#include <stdarg.h>
#include "printf.h"


#include "libft/includes/libft.h"


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

int		ft_octal(char *nbr, int width, char prefix, char filler, int precision)
{
	int		len;

	len = ft_strlen(nbr);
	if (width < 0)
		ft_putnchars(filler, width * -1 - len);
	ft_putstr(nbr);
	if (width > 0)
		ft_putnchars(filler, width - len);
}

int		ft_hex(char *nbr, int width, char prefix, char filler, int precision)
{
	int		len;

	len = ft_strlen(nbr);
	if (width < 0)
		ft_putnchars(filler, width * -1 - len);
	ft_putstr(nbr);
	if (width > 0)
		ft_putnchars(filler, width - len);
}

int		ft_printarg(char *arg, va_list vl)
{
	int		precision;
	int		width;
	int		valid;
	char	filler;
	char	prefix;

	filler = ' ';
	prefix = 0;
	width = -1;
	valid = 1;
	precision = -1;

	int i = 0;
	while (valid)
	{
		i++;
		if (i > 100)
		{
			ft_putstr("error");
			exit(1);
		}
		if (ft_isdigit(*arg))
		{
			if (*arg == '0')
			{
				filler = '0';
				arg++;
			}
			if (width == -1)
				width = ft_atoi(arg) * -1;
			else
				width = ft_atoi(arg);
			while (ft_isdigit(*arg))
				arg++;
		}
		if ((*arg == 'd' || *arg == 'i') && !(valid = 0))
			width = ft_integer(va_arg(vl, int), prefix, width, filler);
		else if (*arg == 'u' && !(valid = 0))
			width = ft_uinteger(ft_abs(va_arg(vl, int)), prefix == '+' ? 1 : 0, width, filler);
		else if (*arg == 'f' && !(valid = 0))
			width = ft_float(va_arg(vl, double), prefix == '+' ? 1 : 0, width, filler, precision);

		else if (*arg == 's' && !(valid = 0))
			width = ft_chars(va_arg(vl, char *), 0 , width, 0, filler, precision);
		else if (*arg == 'c' && !(valid = 0))
			width = ft_chars(NULL, (char)va_arg(vl, int), width, 0, filler, 1);

		else if (*arg == 'o' && !(valid = 0))
			width = ft_octal(ft_itoa_base(va_arg(vl, int), 8, 1), width, prefix, filler, precision);
		else if ((*arg == 'x' || *arg == 'X') && !(valid = 0))
		{
			if (prefix == '#')
				prefix = *arg;
			if (!(width = ft_hex(ft_itoa_base(va_arg(vl, int), 16, *arg == 'x' ? 1 : 0), width, prefix, filler, precision)))
				return (0);
		}
		else if (*arg == 'p' && !(valid = 0))
		{
			if (width < 0)
				ft_putnchars(' ', width * -1 - 14);
			ft_putstr("0x");
			ft_putaddr((va_arg(vl, void *)));
			if (width > 0)
				ft_putnchars(' ', width - 14);
			if (width  > 0)
				width += 14;
			else
				width = 14;
		}
		else if (*arg == '.' && arg++)
		{
			precision = ft_atoi(arg);
			arg += ft_unsignedlen(precision) - 1;
		}
		else if (*arg == '-')
			width = 1;
		else if (*arg == '0')
			filler = '0';
		else if (*arg == '+' || *arg == '#' || *arg == ' ')
			prefix = *arg;
		if ((*arg == '%') && !(valid = 0))
			width = ft_percent(width, filler);
		if (valid)
			arg++;
	}
	return (width);
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
