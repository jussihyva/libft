/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:09:30 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/21 17:54:01 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*start_ptr;
	char		*end_ptr;

	if (*s)
	{
		start_ptr = (char *)s;
		while (*start_ptr && (*start_ptr == ' ' ||
					*start_ptr == '\n' || *start_ptr == '\t'))
		{
			start_ptr++;
		}
		end_ptr = (char *)s + ft_strlen(s) - 1;
		while (end_ptr > start_ptr && (*end_ptr == ' ' ||
					*end_ptr == '\n' || *end_ptr == '\t'))
		{
			end_ptr--;
		}
		if (start_ptr == end_ptr)
			return (ft_strsub(s, 0, 0));
		else
			return (ft_strsub(s, start_ptr - s, end_ptr - start_ptr + 1));
	}
	else
		return (ft_strsub(s, 0, 0));
}
