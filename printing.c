/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:59:41 by vkuikka           #+#    #+#             */
/*   Updated: 2020/02/21 15:19:56 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putstr_len(char *str, size_t len)
{
	write(1, str, ft_strlen(str) > len ? (size_t)len : ft_strlen(str));
}

void	ft_putnchars(char c, int amount)
{
	while (amount > 0)
	{
		write(1, &c, 1);
		amount--;
	}
}

void	ft_putnbr_ull(unsigned long long n)
{
	if (n > 9)
	{
		ft_putnbr_ull(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}
