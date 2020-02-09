/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:25:46 by vkuikka           #+#    #+#             */
/*   Updated: 2019/10/28 12:27:45 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		in;

	i = 0;
	in = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		in = 0;
		i = 0;
		while (haystack[i] == needle[in])
		{
			i++;
			in++;
			if (!needle[in])
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
