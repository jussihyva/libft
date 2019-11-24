/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:19:55 by jkauppi           #+#    #+#             */
/*   Updated: 2019/11/24 14:39:08 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*ft_nbr2str(unsigned int nbr, int count, int neg, char *s)
{
	static char		*letter = "0123456789ABCDEF";

	if (nbr >= 10)
		s = ft_nbr2str(nbr / 10, ++count, neg, s);
	if (neg && !ft_strlen(s))
		*(s + ft_strlen(s)) = '-';
	*(s + ft_strlen(s)) = letter[nbr % 10];
	return (s);
}

static unsigned int	ft_un_int(int n, int neg)
{
	if (neg)
		return ((unsigned int)(n * -1));
	else
		return ((unsigned int)n);
}

static char			*initialize_string(unsigned int unsign_n, int neg)
{
	int		count;
	char	*s;

	count = 1;
	while (unsign_n /= 10)
		count++;
	return (ft_strnew(sizeof(*s) * (count + neg)));
}

char				*ft_itoa(int n)
{
	int				neg;
	unsigned int	unsign_n;
	char			*s;

	neg = 0;
	if (n < 0)
		neg = 1;
	unsign_n = ft_un_int(n, neg);
	s = initialize_string(unsign_n, neg);
	if (s)
		return (ft_nbr2str(unsign_n, 1, neg, s));
	return (0);
}
