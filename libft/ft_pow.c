/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 18:22:09 by vkuikka           #+#    #+#             */
/*   Updated: 2020/02/12 18:27:25 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_pow(long long num, int pow)
{
	long long	tmp;

	tmp = num;
	while (--pow)
		num *= tmp;
	return (num);
}
