/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 19:59:17 by vkuikka           #+#    #+#             */
/*   Updated: 2019/10/28 16:17:33 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(const char *s, char c)
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

static int	ft_size(const char *s, char c, int word)
{
	int		i;
	int		size_i;
	int		len;
	int		*size;

	len = 0;
	i = 0;
	size_i = 0;
	if (!(size = (int *)malloc(sizeof(int) * ft_words(s, c))))
		return ('\0');
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
	return (size[word]);
}

static void	fill_array(char const *s, char c, char **ar)
{
	int		i;
	int		len;
	int		word;

	i = 0;
	len = 0;
	word = 0;
	while (s[i] && word < ft_words(s, c))
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

char		**ft_strsplit(char const *s, char c)
{
	int		word;
	char	**ar;

	word = 0;
	if (!s || !c)
		return (NULL);
	if (!(ar = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1))))
		return (NULL);
	if (!*s)
	{
		*ar = NULL;
		return (ar);
	}
	ar[ft_words(s, c)] = NULL;
	while (word < ft_words(s, c))
	{
		if (!(ar[word] = (char *)malloc(ft_size(s, c, word) + 1)))
			return (NULL);
		word++;
	}
	fill_array(s, c, ar);
	return (ar);
}
