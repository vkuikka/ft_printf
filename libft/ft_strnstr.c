/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 15:25:46 by vkuikka           #+#    #+#             */
/*   Updated: 2019/10/28 12:31:31 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		len_copy;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		len--;
		i = 0;
		len_copy = len;
		while (haystack[i] && haystack[i] == needle[i] && len_copy-- + 1)
			if (!needle[++i])
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
