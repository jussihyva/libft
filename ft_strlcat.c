/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 14:01:16 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/27 10:18:03 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		orig_dst;

	if (dstsize > 0 && ft_memchr(dst, '\0', dstsize))
	{
		orig_dst = ft_strlen(dst);
		ft_strncpy(dst + ft_strlen(dst), src, dstsize - ft_strlen(dst) - 1);
		if (orig_dst + ft_strlen(src) >= dstsize)
			*(dst + dstsize - 1) = '\0';
		return (ft_strlen(src) + orig_dst);
	}
	else
		return (ft_strlen(src) + dstsize);
}
