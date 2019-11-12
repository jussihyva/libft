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

static void		ft_rem_spaces(size_t *index, const char *str)
{
	while (ft_isspace(*(str + *index)))
		(*index)++;
	return ;
}

static int		ft_neg_pos(size_t *index, char c)
{
	if (c == '-' || c == '+')
		(*index)++;
	if (c == '-')
		return (1);
	else
		return (0);
}

static long		ft_read_digits(size_t *index, const char *str, int neg)
{
	long		nbr;

	nbr = 0;
	while (ft_isdigit(*(str + *index)))
	{
		if (add_digit(&nbr, *(str + *index)))
		{
			if (neg)
				nbr = 0;
			else
				nbr = -1;
			break ;
		}
		(*index)++;
	}
	return (nbr);
}

int				ft_atoi(const char *str)
{
	long			nbr;
	int				neg;
	size_t			index;

	index = 0;
	nbr = 0;
	ft_rem_spaces(&index, str);
	neg = ft_neg_pos(&index, *(str + index));
	nbr = ft_read_digits(&index, str, neg);
	if (neg)
		return ((int)(nbr * -1));
	else
		return ((int)(nbr));
}
