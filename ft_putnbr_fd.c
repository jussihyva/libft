/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:21:46 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/30 17:08:36 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	static int		prt_neg;

	prt_neg = 1;
	if (n > 9 || n < -9)
		ft_putnbr_fd(n / 10, fd);
	if (prt_neg && n < 0)
	{
		ft_putchar_fd('-', fd);
		prt_neg = 0;
	}
	if (n < 0)
		ft_putchar_fd('0' - n % 10, fd);
	else
		ft_putchar_fd('0' + n % 10, fd);
	return ;
}
