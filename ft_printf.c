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

char	*ft_skiparg(char *arg)
{
	if (*arg == '%')
		return (arg);
	while (*arg && *arg != 'd' && *arg != 'i' && *arg != 'o' && *arg != 'u' &&
	*arg != 'f' && *arg != 'x' && *arg != 'X' && *arg != 'c' &&
	*arg != 's' && *arg != 'p' && *arg != '%')
		arg++;
	return (arg);
}

int		ft_check_arg(char *arg)
{
	char	*tmp;

	tmp = arg;
	while (*tmp && (*tmp == '-' || *tmp == '+' || *tmp == ' ' ||
			*tmp == '0' || *tmp == '#'))
		tmp++;
	while (*tmp && ft_isdigit(*tmp))
		tmp++;
	if (*tmp == '.' && *(tmp++))
		while (*tmp && ft_isdigit(*tmp))
			tmp++;
	if (*tmp == 'l' || *tmp == 'L')
		while (*tmp && (*tmp == 'l' || *tmp == 'L'))
			tmp++;
	else if (*tmp == 'h')
		while (*tmp && *tmp == 'h')
			tmp++;
	if (*tmp == 'd' || *tmp == 'i' || *tmp == 'o' || *tmp == 'u' ||
	*tmp == 'f' || *tmp == 'x' || *tmp == 'X' || *tmp == 'c' ||
	*tmp == 's' || *tmp == 'p' || *tmp == '%')
		return (1);
	return (0);
}

t_nums	ft_info_init(void)
{
	t_nums	info;

	info.precision = -1;
	info.filler = ' ';
	info.prefix = 0;
	info.width = 0;
	info.width_pos = 1;
	info.valid = 1;
	info.intsize = 0;
	return (info);
}

int		ft_printarg(char *arg, va_list vl)
{
	t_nums	info;

	info = ft_info_init();
	while (info.valid && *arg)
	{
		if (*arg == '0' && info.precision == -1 && (info.filler = '0'))
			arg++;
		if (ft_isdigit(*arg) && info.precision == -1)
		{
			info.width = ft_atoi(arg);
			while (ft_isdigit(*arg))
				arg++;
		}
		if ((*arg == 'd' || *arg == 'i' || *arg == 'u' || *arg == 'f') &&
				!(info.valid = 0))
			info.width = ft_nums(vl, info, *arg);
		else if ((*arg == 's' || *arg == 'c' || *arg == 'o' ||
				*arg == 'x' || *arg == 'X' || *arg == 'p') && !(info.valid = 0))
			info.width = ft_chars(vl, info, *arg);
		else
			info = ft_flags(arg, info);
		arg = info.valid && *arg ? arg + 1 : arg;
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
		if (*arg == '%' && *(++arg) && ft_check_arg(arg))
		{
			if (*arg == '%' && ++len)
				write(1, &*arg, 1);
			else if (*arg)
				len += ft_printarg(arg, vl);
			arg = ft_skiparg(arg);
		}
		else if (*arg && ++len)
			write(1, &*arg, 1);
		if (*arg)
			arg++;
	}
	va_end(vl);
	return (len);
}
