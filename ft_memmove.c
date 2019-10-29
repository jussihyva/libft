/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:21:00 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/29 14:40:39 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			index;

	if (src != dst)
	{
		if (src < dst)
		{
			while (len--)
				*(unsigned char *)(dst + len) =
					*(unsigned char *)(src + len);
		}
		else
		{
			index = 0;
			while (index++ < len)
				*(unsigned char *)(dst + index - 1) =
					*(unsigned char *)(src + index - 1);
		}
	}
	return (dst);
}
