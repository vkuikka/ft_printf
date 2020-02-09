/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:14:24 by vkuikka           #+#    #+#             */
/*   Updated: 2019/12/02 18:40:04 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_arr(char **array, unsigned arr_len, unsigned str_len)
{
	unsigned	x;
	unsigned	y;

	x = 0;
	y = 0;
	while (y < arr_len)
	{
		x = 0;
		while (x < str_len)
		{
			write(1, &array[y][x], 1);
			write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}
