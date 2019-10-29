/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:03:28 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/29 14:57:59 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*new_str;
	size_t		index;

	new_str = (char *)ft_memalloc(ft_strlen(s) + 1);
	if (new_str && s && f)
	{
		index = 0;
		while (*(s + index))
		{
			*(new_str + index) = f(*(s + index));
			index++;
		}
		return (new_str);
	}
	else
		return (NULL);
}
