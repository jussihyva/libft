/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 12:05:30 by jkauppi           #+#    #+#             */
/*   Updated: 2020/08/23 12:01:33 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		add_digit(long *nbr, char c)
{
	long		tmp;

	if (!ft_isdigit(c))
		return (0);
	tmp = (*nbr * 10) + (c - '0');
	if (tmp >= *nbr)
	{
		*nbr = tmp;
		return (1);
	}
	else
	{
		*nbr = 0;
		errno = ERANGE;
		return (0);
	}
}

static void		set_endptr(char **endptr, const char *str)
{
	if (endptr)
	{
		*endptr = (char *)str;
		if (*str)
			errno = EINVAL;
	}
	return ;
}

int				ft_strtoi(const char *str, char **endptr, int base)
{
	int			neg;
	long		nbr;
	const char	*start_ptr;

	(void)base;
	errno = 0;
	start_ptr = str;
	while (ft_isspace(*str))
		str++;
	errno = start_ptr != str ? EINVAL : errno;
	neg = *str == '-' ? -1 : 1;
	str += (*str == '-' || *str == '+') ? 1 : 0;
	nbr = 0;
	start_ptr = str;
	while (add_digit(&nbr, *str))
		str++;
	errno = start_ptr == str ? EINVAL : errno;
	if ((neg * nbr) > INT_MAX || (neg * nbr) < INT_MIN)
	{
		errno = ERANGE;
		nbr = 0;
	}
	set_endptr(endptr, str);
	return (neg == 1 ? (int)nbr : (int)(nbr * -1));
}
