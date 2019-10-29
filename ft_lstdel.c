/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 16:50:06 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/28 17:23:12 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*elem;

	elem = *alst;
	while (elem)
	{
		elem = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		ft_memdel((void**)alst);
		*alst = elem;
	}
	*alst = NULL;
}
