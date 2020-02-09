/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:31:46 by vkuikka           #+#    #+#             */
/*   Updated: 2019/10/28 11:08:01 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len_1;
	int		len_2;

	len_1 = 0;
	len_2 = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[len_1])
		len_1++;
	while (s2[len_2])
		len_2++;
	if (!(str = (char *)malloc(len_1 + len_2 + 1)))
		return (NULL);
	len_1 = 0;
	len_2 = 0;
	while (s1[len_1])
	{
		str[len_1] = s1[len_1];
		len_1++;
	}
	while (s2[len_2])
		str[len_1++] = s2[len_2++];
	str[len_1] = '\0';
	return (str);
}
