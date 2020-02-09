/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 19:53:44 by vkuikka           #+#    #+#             */
/*   Updated: 2019/10/24 22:18:58 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	size_t		i;
	size_t		num;
	size_t		mult;
	int			negative;

	i = 0;
	mult = 1;
	num = 0;
	negative = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\v' || str[i] == '\t' ||
				str[i] == '\n' || str[i] == '\f' || str[i] == '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		negative = (str[i++] == '-' ? -1 : 1);
	negative = (str[i] >= '0' || str[i] <= '9' ? negative : 0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		num += (str[i] - '0') * mult;
		mult *= 10;
		i--;
	}
	return (num * negative);
}
