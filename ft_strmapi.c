/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:32:45 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/28 08:47:58 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*new_str;

	new_str = (char *)ft_memalloc(ft_strlen(s) + 1);
	if (new_str)
	{
		index = 0;
		while (*(s + index))
		{
			*(new_str + index) = f(index, *(s + index));
			index++;
		}
		return (new_str);
	}
	else
		return (NULL);
}
