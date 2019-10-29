/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 11:52:49 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/22 12:23:50 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	static int		prt_neg;

	prt_neg = 1;
	if (n > 9 || n < -9)
		ft_putnbr(n / 10);
	if (prt_neg && n < 0)
	{
		prt_neg = 0;
		ft_putchar('-');
	}
	if (n < 0)
		ft_putchar('0' - n % 10);
	else
		ft_putchar('0' + n % 10);
}
