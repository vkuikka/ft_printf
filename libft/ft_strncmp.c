/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 11:07:28 by vkuikka           #+#    #+#             */
/*   Updated: 2019/10/27 17:31:41 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*c1;
	unsigned char	*c2;

	i = 0;
	c1 = ((unsigned char *)s1);
	c2 = ((unsigned char *)s2);
	if ((!c1[0] && !c2[0]) || n == 0)
		return (0);
	while (c1[i] == c2[i] && c1[i] && c2[i] && i + 1 < n)
		i++;
	return (c1[i] - c2[i]);
}
