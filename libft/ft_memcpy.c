/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:39:49 by vkuikka           #+#    #+#             */
/*   Updated: 2019/12/03 15:11:47 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	unsigned	*ptr;
	unsigned	*ptr2;

	i = 0;
	ptr = (unsigned *)src;
	ptr2 = (unsigned *)dst;
	while (i < n)
	{
		ptr2[i] = ptr[i];
		i++;
	}
	dst = (void *)ptr2;
	return (dst);
}
