/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_char_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 22:16:59 by vkuikka           #+#    #+#             */
/*   Updated: 2019/12/03 15:11:19 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_new_char_arr(unsigned str_len, unsigned arr_len)
{
	char			**ret;
	unsigned		i;

	i = 0;
	if (!(ret = (char **)malloc(sizeof(char*) * arr_len)))
		return (NULL);
	while (i < arr_len)
	{
		if (!(ret[i] = (char *)malloc(sizeof(char) * str_len)))
			return (NULL);
		ft_bzero(ret[i], str_len);
		i++;
	}
	return (ret);
}
