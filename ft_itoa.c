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

static char		*ft_nbr2str(unsigned int nbr, int count, int neg)
{
	static char		*str;
	static char		*letter = "0123456789ABCDEF";

	if (nbr >= 10)
		str = ft_nbr2str(nbr / 10, ++count, neg);
	if (!str)
		str = (char *)ft_strnew(sizeof(*str) * (count + neg));
	if (neg && !ft_strlen(str))
		*(str + ft_strlen(str)) = '-';
	*(str + ft_strlen(str)) = letter[nbr % 10];
	return (str);
}

static unsigned int	ft_un_int(int n, int neg)
{
	if (neg)
		return ((unsigned int)(n * -1));
	else
		return ((unsigned int)n);
}

char			*ft_itoa(int n)
{
	int			neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	return (ft_nbr2str(ft_un_int(n, neg), 1, neg));
}
