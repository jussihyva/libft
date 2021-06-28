/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:50:06 by jkauppi           #+#    #+#             */
/*   Updated: 2021/04/09 13:42:19 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list			*elem;
	t_list			*next_elem;

	if (alst)
	{
		elem = *alst;
		while (elem)
		{
			next_elem = elem->next;
			ft_lstdelone(&elem, del);
			elem = next_elem;
		}
		*alst = NULL;
	}
}
