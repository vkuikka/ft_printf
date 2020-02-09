/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:39:44 by vkuikka           #+#    #+#             */
/*   Updated: 2019/11/04 14:59:08 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*str;
	size_t		len;
	size_t		i;

	i = 0;
	len = 0;
	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (s[len])
		len++;
	len--;
	while (*s && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	if (!(str = (char *)malloc(sizeof(char) * (len++ + 1))))
		return (NULL);
	while (len)
	{
		str[i] = s[i];
		i++;
		len--;
	}
	str[i] = '\0';
	return (str);
}
