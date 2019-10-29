/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/18 12:40:07 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/24 18:12:39 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		index;
	size_t		s1_length;

	s1_length = ft_strlen(s1);
	index = 0;
	while (index < n && *(s2 + index))
	{
		*(s1 + s1_length + index) = *(s2 + index);
		index++;
	}
	*(s1 + s1_length + index) = '\0';
	return (s1);
}
