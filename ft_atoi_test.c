/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:51:13 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/28 17:30:19 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		ft_atoi_test(void)
{
	char	*str1;

	str1 = ft_strdup("9223372036854775807");
	ft_putnbr(atoi(str1));
	ft_putchar(' ');
	ft_putnbr(ft_atoi(str1));
	ft_putchar('\n');
	str1 = ft_strdup("-9223372036854775808");
	ft_putnbr(atoi(str1));
	ft_putchar(' ');
	ft_putnbr(ft_atoi(str1));
	ft_putchar('\n');
	str1 = ft_strdup("9223372036854775808");
	ft_putnbr(atoi(str1));
	ft_putchar(' ');
	ft_putnbr(ft_atoi(str1));
	ft_putchar('\n');
	str1 = ft_strdup("-9223372036854775809");
	ft_putnbr(atoi(str1));
	ft_putchar(' ');
	ft_putnbr(ft_atoi(str1));
	ft_putchar('\n');
}
