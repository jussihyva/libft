/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 11:45:04 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/26 18:47:57 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char		*ptr;

	if ((ptr = ft_memccpy(dst, src, '\0', len)))
	{
		while ((size_t)(ptr - dst) < len)
		{
			*ptr = '\0';
			ptr++;
		}
	}
	return (dst);
}
