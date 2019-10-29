/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:21:22 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/23 18:56:18 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t		index;
	char		*sub_str;

	if ((start + len) <= ft_strlen(s))
	{
		sub_str = (char *)ft_memalloc(len + 1);
		if (sub_str)
		{
			index = 0;
			while (index < len)
			{
				*(sub_str + index) = *(s + start + index);
				index++;
			}
			*(sub_str + index) = '\0';
			return (sub_str);
		}
		else
			return (NULL);
	}
	else
		return (NULL);
}
