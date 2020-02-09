/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:53:07 by vkuikka           #+#    #+#             */
/*   Updated: 2019/11/22 19:52:37 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ls;

	if (!(ls = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (content && content_size)
	{
		if (!(ls->content = (void *)malloc(content_size)))
			return (NULL);
		ls->content = ft_memcpy(ls->content, content, content_size);
		ls->content_size = content_size;
	}
	else
	{
		ls->content = NULL;
		ls->content_size = 0;
	}
	ls->next = NULL;
	return (ls);
}
