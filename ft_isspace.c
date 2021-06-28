/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 17:56:02 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/27 10:09:07 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	char		space_array[7];
	int			index;

	space_array[0] = '\t';
	space_array[1] = '\n';
	space_array[2] = '\v';
	space_array[3] = '\f';
	space_array[4] = '\r';
	space_array[5] = ' ';
	space_array[6] = '\0';
	index = 0;
	while (*(space_array + index) && *(space_array + index) != c)
		index++;
	return (*(space_array + index));
}
