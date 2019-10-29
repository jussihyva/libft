/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 12:25:17 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/28 08:49:16 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*str;

	str = (char *)ft_memalloc(size + 1);
	if (str)
	{
		ft_bzero(str, (size + 1));
		return (str);
	}
	else
		return (NULL);
}
