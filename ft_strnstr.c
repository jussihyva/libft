/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:19:42 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/29 15:11:06 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haystack_index;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	haystack_index = 0;
	while (*(haystack + haystack_index) && haystack_index +
			ft_strlen(needle) <= len)
	{
		if (ft_strncmp(haystack + haystack_index, needle, ft_strlen(needle)))
			haystack_index++;
		else
			return (char *)(haystack + haystack_index);
	}
	return (NULL);
}
