/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:02:02 by jkauppi           #+#    #+#             */
/*   Updated: 2019/11/12 12:51:51 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		add_digit(long *nbr, char c, int neg)
{
	long		tmp;

	if (ft_isdigit(c))
	{
		tmp = (*nbr * 10) + (c - '0');
		if (tmp >= *nbr)
		{
			*nbr = tmp;
			return (1);
		}
		*nbr = -1;
		if (neg)
			*nbr = 0;
	}
	return (0);
}

int				ft_atoi(const char *str)
{
	long			nbr;
	int				neg;

	while (ft_isspace(*str))
		str++;
	neg = 0;
	if (*str == '-')
		neg = 1;
	if (*str == '-' || *str == '+')
		str++;
	nbr = 0;
	while (add_digit(&nbr, *str, neg))
		str++;
	if (neg)
		return ((int)(nbr * -1));
	return ((int)(nbr));
}
