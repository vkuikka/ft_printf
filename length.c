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

int		ft_numlen_base(unsigned long long nb, int base)
{
	int		i;

	i = 1;
	while (nb /= base)
		i++;
	return (i);
}
