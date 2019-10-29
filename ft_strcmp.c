/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:14:24 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/25 08:13:27 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t		index;

	index = 0;
	while (*(unsigned char *)(s1 + index) == *(unsigned char *)(s2 + index))
	{
		if (*(s1 + index))
			index++;
		else
			return (0);
	}
	return ((int)(*(unsigned char *)(s1 + index) -
				*(unsigned char *)(s2 + index)));
}
