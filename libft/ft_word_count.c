/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_word_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 19:22:09 by vkuikka           #+#    #+#             */
/*   Updated: 2019/11/03 19:25:17 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_word_count(const char *s, const char c)
{
	int		i;
	int		w;

	w = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		while (s[i] == c && s[i])
			i++;
		w++;
	}
	if (s[0] == c)
		w--;
	if (s[i] == c)
		w--;
	return (w);
}
