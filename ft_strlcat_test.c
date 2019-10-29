/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:02:54 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/26 19:45:08 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		ft_strlcat_test(void)
{
	char		*str1;
	char		*str2;
	size_t		dstsize;

	ft_putendl("ft_strlcat");
	dstsize = 20;
	while (dstsize-- > 0)
	{
		str1 = ft_strdup("Source");
		str2 = ft_strdup("Dest");
		ft_putnbr(dstsize);
		ft_putstr(": ");
		ft_putnbr(strlcat(str2, str1, dstsize));
		ft_putchar(' ');
		ft_putstr(str2);
		ft_putchar(' ');
		str1 = ft_strdup("Source");
		str2 = ft_strdup("Dest");
		ft_putnbr(ft_strlcat(str2, str1, dstsize));
		ft_putchar(' ');
		ft_putstr(str2);
		ft_putchar('\n');
	}
}
