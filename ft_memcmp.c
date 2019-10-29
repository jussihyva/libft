/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:11:03 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/26 18:27:34 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		index;

	index = 0;
	while (index < n && *((unsigned char *)(s1 + index)) ==
			*((unsigned char *)(s2 + index)))
		index++;
	if (index == n)
		return (0);
	else
		return (*((unsigned char *)(s1 + index)) -
				*((unsigned char *)(s2 + index)));
}
