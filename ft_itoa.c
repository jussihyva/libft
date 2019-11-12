/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:19:55 by jkauppi           #+#    #+#             */
/*   Updated: 2019/11/12 13:23:41 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_nbr2str(long nbr, int count, int neg)
{
	static char		*str;

	if (nbr > 9 || nbr < -9)
		str = ft_nbr2str(nbr / 10, ++count, neg);
	if (!str)
		str = (char *)ft_strnew(sizeof(*str) * (count + neg));
	if (neg)
	{
		if (!ft_strlen(str) && neg)
			*(str + ft_strlen(str)) = '-';
		*(str + ft_strlen(str)) = '0' - (nbr % 10);
	}
	else
		*(str + ft_strlen(str)) = '0' + (nbr % 10);
	return (str);
}

char			*ft_itoa(int n)
{
	int			neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	return (ft_nbr2str(n, 1, neg));
}
