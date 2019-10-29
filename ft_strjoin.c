/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 16:54:23 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/28 15:30:24 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*joint_str;

	if ((joint_str = (char *)ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
	{
		ft_strcpy(joint_str, s1);
		ft_strcpy(joint_str + ft_strlen(s1), s2);
		return (joint_str);
	}
	else
		return (NULL);
}
