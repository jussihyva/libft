/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 18:58:16 by jkauppi           #+#    #+#             */
/*   Updated: 2020/03/07 13:33:54 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (*alst)
	{
		new->next = *alst;
		new->prev = (*alst)->prev;
		(*alst)->prev = new;
		*alst = new;
	}
	else
	{
		*alst = new;
		(*alst)->next = NULL;
		(*alst)->prev = NULL;
	}
	return ;
}
