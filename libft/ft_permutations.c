/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permutations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:01:06 by vkuikka           #+#    #+#             */
/*   Updated: 2019/12/03 15:01:35 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_permutations(int a[], int size, int n)
{
	int			i;
	static int	**res = NULL;
	static int	res_i = 0;

	i = 0;
	if (!res)
		res = ft_new_int_arr(n, ft_factorial(n));
	if (size == 1)
		ft_memcpy(res[res_i++], a, n);
	while (i < size)
	{
		ft_permutations(a, size - 1, n);
		if (size % 2)
			ft_swap(&a[0], &a[size - 1]);
		else
			ft_swap(&a[i], &a[size - 1]);
		i++;
	}
	return (res);
}
