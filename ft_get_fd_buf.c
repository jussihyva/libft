/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fd_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:24:31 by jkauppi           #+#    #+#             */
/*   Updated: 2019/11/05 18:21:38 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

char	**ft_get_fd_buf(int fd, size_t size)
{
	static t_fd_elem	*fd_table[MAX_NUM_FD];
	size_t				index;
	int					next_free;
	char				**buffer;

	index = 0;
	next_free = -1;
	while (index < MAX_NUM_FD)
	{
		if (fd_table[index])
		{
			if (fd_table[index]->fd == fd)
			{
				buffer = &(fd_table[index]->buffer);
				break;
			}
		}
		else if (next_free < 0)
            next_free = index;
		index++;
	}
	if (index == MAX_NUM_FD)
	{
	    index = next_free;
		fd_table[index] = (t_fd_elem *)memalloc(sizeof(t_fd_elem));
        fd_table[index]->buffer = ft_strnew(size);
	}
	buffer = &(fd_table[index]->buffer);
	return (&buffer);
}