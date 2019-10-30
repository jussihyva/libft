/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_e.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 08:10:44 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/30 16:46:36 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_e(t_list **alst, t_list *new)
{
	t_list	*elem;

	elem = *alst;
	while (elem->next)
		elem = elem->next;
	elem->next = new;
	return ;
}
