/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 20:00:00 by vkuikka           #+#    #+#             */
/*   Updated: 2019/11/04 15:08:00 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_fill_array(char const *s, char c, char **ar)
{
	int		i;
	int		len;
	int		word;

	i = 0;
	len = 0;
	word = 0;
	while (s[i] && word < ft_word_count(s, c))
	{
		len = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c)
		{
			ar[word][len] = s[i];
			len++;
			i++;
		}
		ar[word][len] = '\0';
		word++;
	}
}
