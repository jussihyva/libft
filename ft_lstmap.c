/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 07:46:53 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/28 08:07:38 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_lst;
	t_list		*src_elem;

	src_elem = lst;
	new_lst = f(src_elem);
	src_elem = src_elem->next;
	while (src_elem)
	{
		ft_lstadd_e(&new_lst, f(src_elem));
		src_elem = src_elem->next;
	}
	return (new_lst);
}
