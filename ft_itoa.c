/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 10:19:55 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/28 17:26:52 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(int n)
{
	size_t		count;

	count = 1;
	while (n > 9 || n < -9)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	size_t		count;
	char		*str;
	int			tmp_n;
	int			neg;

	neg = 0;
	if (n < 0)
		neg = 1;
	count = ft_count_digits(n);
	if ((str = ft_strnew(count + neg)))
	{
		tmp_n = n;
		while (count-- > 0)
		{
			if (neg)
				*(str + neg + count) = '0' - tmp_n % 10;
			else
				*(str + neg + count) = '0' + tmp_n % 10;
			tmp_n = tmp_n / 10;
		}
		if (neg)
			*str = '-';
		return (str);
	}
	return (NULL);
}
