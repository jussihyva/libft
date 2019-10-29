/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:56:02 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/27 18:28:51 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace(char c)
{
	char		space_array[6];
	size_t		index;

	space_array[0] = '\t';
	space_array[1] = '\n';
	space_array[2] = '\v';
	space_array[3] = '\f';
	space_array[4] = '\r';
	space_array[5] = ' ';
	index = 0;
	while (index < 6 && *(space_array + index) != c)
		index++;
	if (index == 6)
		return (0);
	else
		return (1);
}
