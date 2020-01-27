/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:51:20 by jkauppi           #+#    #+#             */
/*   Updated: 2020/01/26 16:14:01 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*elem;

	if ((elem = (t_list *)ft_memalloc(sizeof(*elem))))
	{
		if (content)
		{
			if ((elem->content = ft_memalloc(content_size)))
			{
				elem->content = ft_memcpy(elem->content, content, content_size);
				elem->content_size = content_size;
			}
		}
		else
		{
			elem->content = NULL;
			elem->content_size = 0;
		}
		elem->next = NULL;
		elem->prev = NULL;
	}
	return (elem);
}
