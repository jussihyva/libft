/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:03:25 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/23 18:14:19 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			index;

	index = 0;
	while (index < n && *(unsigned char *)(src + index) != (unsigned char)c)
	{
		*((unsigned char *)(dst + index)) = *((unsigned char *)(src + index));
		index++;
	}
	if (index == n)
		return (NULL);
	else
	{
		*((unsigned char *)(dst + index)) = *((unsigned char *)(src + index));
		return (dst + index + 1);
	}
}
