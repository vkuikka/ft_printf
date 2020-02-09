/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 19:00:02 by vkuikka           #+#    #+#             */
/*   Updated: 2019/10/27 19:46:26 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*copy;

	i = 0;
	if (!s || !*s)
		return (NULL);
	while (s[i])
		i++;
	if (!(copy = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	copy[i] = '\0';
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	i = 0;
	while (copy[i])
	{
		copy[i] = f(i, copy[i]);
		i++;
	}
	return (copy);
}
