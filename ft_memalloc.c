/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 08:45:35 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/21 12:02:38 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*mem_area;

	if (!(mem_area = malloc(size)))
	{
		ft_putstr("MAJOR ERROR: Memory allocation failed.\n");
		exit(42);
	}
	ft_bzero(mem_area, size);
	return (mem_area);
}
