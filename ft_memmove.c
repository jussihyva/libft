/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:21:00 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/27 10:12:27 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;

	if (src < dst)
	{
		while (len--)
			*(unsigned char *)(dst + len)
				= *(unsigned char *)(src + len);
	}
	else if (src > dst)
	{
		index = 0;
		while (index++ < len)
			*(unsigned char *)(dst + index - 1)
				= *(unsigned char *)(src + index - 1);
	}
	return (dst);
}
