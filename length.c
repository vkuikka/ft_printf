/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:45:58 by vkuikka           #+#    #+#             */
/*   Updated: 2020/01/29 17:49:26 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_signedlen(long long num)
{
	unsigned long long	div;
	int					len;

	div = 10;
	len = num < 0 ? 2 : 1;
	if (num < 0)
		num *= -1;
	while (num / div)
	{
		div *= 10;
		len++;
	}
	return (len);
}

int		ft_unsignedlen(unsigned long long num)
{
	unsigned long long	div;
	int					len;

	div = 10;
	len = 1;
	if (num > 9999999999999999999U)
		return (20);
	while (num / div)
	{
		div *= 10;
		len++;
	}
	return (len);
}

size_t	ft_numlen_base(long nb, int base)
{
	size_t		i;

	i = 1;
	while (nb /= base)
		i++;
	return (i);
}

void	ft_putstr_len(char *str, size_t len)
{
	if (len > 0)
		write(1, str, ft_strlen(str) > len ? (size_t)len : ft_strlen(str));
	else
		write(1, str, ft_strlen(str));
}

void	ft_putnchars(char c, int amount)
{
	while (amount > 0)
	{
		write(1, &c, 1);
		amount--;
	}
}
