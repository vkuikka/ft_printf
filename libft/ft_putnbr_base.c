/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 16:16:02 by vkuikka           #+#    #+#             */
/*   Updated: 2020/02/09 16:16:44 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(unsigned long long n, int base, int lowercase)
{
	char	*b;

	b = lowercase ? "0123456789abcdef" : "0123456789ABCDEF";
	if (n > (unsigned long long)base - 1)
	{
		if (n / base)
			ft_putnbr_base(n / base, base, lowercase);
		ft_putchar(b[n % base]);
	}
	else
		ft_putchar(b[n]);
}
