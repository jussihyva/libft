/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:11:03 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/27 10:10:51 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			index;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	index = 0;
	while (index < n && *(str1 + index) == *(str2 + index))
		index++;
	if (index == n)
		return (0);
	else
		return ((int)(*(str1 + index) - *(str2 + index)));
}
