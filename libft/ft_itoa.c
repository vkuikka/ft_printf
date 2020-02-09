/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 22:37:27 by vkuikka           #+#    #+#             */
/*   Updated: 2019/12/06 20:02:38 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*str;
	int				chars;
	long			div;
	long			num;

	num = n;
	div = 10;
	chars = (num < 0 ? 2 : 1);
	while (num / div && chars++ > 0)
		div *= 10;
	if (!(str = (char *)malloc(sizeof(char) * (chars + 1))))
		return (NULL);
	str[chars--] = '\0';
	str[0] = num < 0 ? '-' : '0';
	num *= num < 0 ? -1 : 1;
	while (chars >= (str[0] == '-' ? 1 : 0))
	{
		str[chars] = num % 10 + '0';
		num /= 10;
		chars--;
	}
	return (str);
}
