/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:44:45 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/21 13:57:21 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	size_t		index;

	index = 0;
	while (*(s1 + index) && *(s1 + index) == *(s2 + index))
		index++;
	if (*(s1 + index) || *(s2 + index))
		return (0);
	else
		return (1);
}
