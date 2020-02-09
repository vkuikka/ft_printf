/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkuikka <vkuikka@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 18:41:38 by vkuikka           #+#    #+#             */
/*   Updated: 2019/10/29 18:41:40 by vkuikka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;

	new = *alst;
	if (!alst || !del)
		return ;
	while (new)
	{
		del(new->content, new->content_size);
		free(new);
		new = new->next;
	}
	*alst = NULL;
}
