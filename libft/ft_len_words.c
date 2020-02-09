/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:38:21 by vkuikka           #+#    #+#             */
/*   Updated: 2019/11/03 19:40:29 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_len_words(const char *s, const char c)
{
	int		i;
	int		size_i;
	int		len;
	int		*size;

	len = 0;
	i = 0;
	size_i = 0;
	size = (int *)malloc(sizeof(int) * ft_word_count(s, c));
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		while (s[i] == c && s[i])
			i++;
		size[size_i] = len;
		size_i += 1;
		len = 0;
	}
	return (size);
}
