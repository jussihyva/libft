/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 11:53:50 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/27 17:55:20 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strsplit_test(void)
{
	char	*str1;
	char	**str_array;
	size_t	index;

	ft_putendl("  Start");
	str1 = ft_strdup("lorem1234567890 ipsum1234567890 dolor sit amet \
			consectetur adipiscing elit Sed non risus Suspendisse");
	str_array = ft_strsplit(str1, ' ');
	ft_putendl("  Mid");
	index = 0;
	while (*(str_array + index))
	{
		ft_putendl(*(str_array + index));
		index++;
	}
	ft_putendl("  End");
}
