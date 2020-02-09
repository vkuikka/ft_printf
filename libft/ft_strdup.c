/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:29:41 by vkuikka           #+#    #+#             */
/*   Updated: 2019/12/13 17:50:59 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		count;
	char	*str;

	count = -1;
	i = 0;
	while (src[i])
		i++;
	if (!(str = (char*)malloc(sizeof(str) * i)))
		return (NULL);
	while (++count < i)
		str[count] = src[count];
	str[count] = '\0';
	return (str);
}
