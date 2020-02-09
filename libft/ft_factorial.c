/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 18:17:06 by vkuikka           #+#    #+#             */
/*   Updated: 2019/12/02 18:26:44 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_factorial(int num)
{
	int		i;

	i = num - 1;
	while (i)
	{
		num *= i;
		i--;
	}
	return (num);
}
