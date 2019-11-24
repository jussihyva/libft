/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fd_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:24:31 by jkauppi           #+#    #+#             */
/*   Updated: 2019/11/24 16:29:43 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fd_elem	**ft_get_fd_buf(int fd, size_t size)
{
	static t_fd_elem	*fd_table[MAX_NUM_FD];
	size_t				index;
	int					next_free;

	index = 0;
	next_free = -1;
	while (index < MAX_NUM_FD)
	{
		if (fd_table[index] && fd_table[index]->fd == fd)
			break ;
		else if (!fd_table[index] && next_free < 0)
			next_free = index;
		index++;
	}
	if (index == MAX_NUM_FD)
	{
		index = next_free;
		if ((fd_table[index] = (t_fd_elem *)ft_memalloc(sizeof(t_fd_elem))))
		{
			fd_table[index]->buffer = ft_strnew(size);
			fd_table[index]->read_ptr = fd_table[index]->buffer;
			fd_table[index]->fd = fd;
		}
	}
	return (fd_table + index);
}
