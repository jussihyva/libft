/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:40:02 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/26 18:28:40 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		index;

	index = 0;
	while (index < n &&
			*(unsigned char *)(s1 + index) == *(unsigned char *)(s2 + index))
	{
		if (*(s1 + index) && *(s2 + index))
			index++;
		else
			return (0);
	}
	if (index < n)
		return ((int)(*(unsigned char *)(s1 + index) -
					*(unsigned char *)(s2 + index)));
	else
		return (0);
}
