/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:46:24 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/27 09:48:11 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		haystack_index;

	if (!ft_strlen(needle))
		return ((char *)haystack);
	haystack_index = 0;
	while (*(haystack + haystack_index))
	{
		if (ft_strncmp(haystack + haystack_index, needle, ft_strlen(needle)))
			haystack_index++;
		else
			return ((char *)(haystack + haystack_index));
	}
	return (NULL);
}
