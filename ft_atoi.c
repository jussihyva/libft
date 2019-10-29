/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 15:02:02 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/29 07:34:29 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		create_nbr(unsigned int nbr, int neg)
{
	if (neg)
		return ((int)nbr * -1);
	else
		return (int)(nbr);
}

static int		is_valid_char(long *nbr, int *neg, char c)
{
	if (c == '-')
		*neg = 1;
	else if (c == '+')
		*neg = 0;
	else if (ft_isdigit(c))
	{
		if (c != '0')
		{
			*neg = 0;
			*nbr = (*nbr * 10) + (c - '0');
		}
	}
	else if (ft_isspace(c))
	{
	}
	else
		return (0);
	return (1);
}

static int		add_digit(long *nbr, char c)
{
	long		tmp;

	tmp = (*nbr * 10) + (c - '0');
	if (tmp >= *nbr)
	{
		*nbr = tmp;
		return (0);
	}
	else
		return (1);
}

static int		ft_undefined(int neg)
{
	if (neg)
		return (0);
	return (-1);
}

int				ft_atoi(const char *str)
{
	long			nbr;
	int				neg;
	size_t			index;

	index = -1;
	neg = -1;
	nbr = 0;
	while (*(str + ++index))
	{
		if (nbr == 0 && neg < 0)
		{
			if (!is_valid_char(&nbr, &neg, *(str + index)))
				return (0);
		}
		else
		{
			if (!(ft_isdigit(*(str + index))))
				return (create_nbr(nbr, neg));
			if (add_digit(&nbr, *(str + index)))
				return (ft_undefined(neg));
		}
	}
	return (create_nbr(nbr, neg));
}
