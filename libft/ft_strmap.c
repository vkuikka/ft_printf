/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:39:25 by vkuikka           #+#    #+#             */
/*   Updated: 2019/10/25 12:38:44 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
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
		copy[i] = f(copy[i]);
		i++;
	}
	return (copy);
}
