/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:45:04 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/27 10:16:05 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*ptr;

	ptr = ft_memccpy(dst, src, '\0', len);
	if (ptr)
	{
		while ((size_t)(ptr - dst) < len)
		{
			*ptr = '\0';
			ptr++;
		}
	}
	return (dst);
}
