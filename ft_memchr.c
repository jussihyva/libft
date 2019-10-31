/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:38:49 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/26 18:27:09 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			index;

	index = 0;
	while (index < n && *((unsigned char *)(s + index)) != (unsigned char)c)
		index++;
	if (index == n)
		return (NULL);
	return ((void *)(s + index));
}
