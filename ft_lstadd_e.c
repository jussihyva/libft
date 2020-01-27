/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 08:10:44 by jkauppi           #+#    #+#             */
/*   Updated: 2020/01/26 16:20:13 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_e(t_list **alst, t_list *new)
{
	t_list	*elem;

	if (*alst)
	{
		elem = *alst;
		while (elem->next)
			elem = elem->next;
		elem->next = new;
		new->prev = elem;
	}
	else
		*alst = new;
	return ;
}
