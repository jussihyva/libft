/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:02:52 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/27 10:16:15 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t		index;

	index = 0;
	while (*(s1 + index) && *(s1 + index) == *(s2 + index) && index < n)
		index++;
	if (*(s1 + index))
	{
		if (index == n)
			return (1);
		else
			return (0);
	}
	else
	{
		if (*(s2 + index))
		{
			if (index == n)
				return (1);
			else
				return (0);
		}
		else
			return (1);
	}
}
