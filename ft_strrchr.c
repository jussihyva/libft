/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:12:34 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/27 11:13:35 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		*ptr;
	char		*match_ptr;

	if ((char)c == '\0')
		return ((char *)(s + ft_strlen(s)));
	else
	{
		match_ptr = NULL;
		ptr = (char *)s;
		while (ptr && *ptr)
		{
			if ((ptr = ft_memchr(ptr, c, ft_strlen(ptr) + 1)))
			{
				match_ptr = ptr;
				ptr++;
			}
		}
		return (match_ptr);
	}
}
