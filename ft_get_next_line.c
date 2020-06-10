/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 10:24:46 by jkauppi           #+#    #+#             */
/*   Updated: 2020/04/08 16:36:30 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int			ft_build_new_line(t_fd_elem **fd_elem, char **line,
		char *match_ptr, t_list **elem_lst)
{
	t_list		*elem;
	t_list		*tmp;

	if (!(*line = ft_strnew(match_ptr - (*fd_elem)->read_ptr +
						(*fd_elem)->saved_chars)))
		return (-1);
	*match_ptr = '\0';
	if (elem_lst && *elem_lst)
	{
		elem = *elem_lst;
		while (elem)
		{
			tmp = elem->next;
			ft_strcat(*line, elem->content);
			ft_strdel((char **)&(elem->content));
			free(elem);
			elem = tmp;
		}
		*elem_lst = NULL;
		ft_strcat(*line, (*fd_elem)->read_ptr);
	}
	else
		*line = ft_strcpy(*line, (*fd_elem)->read_ptr);
	(*fd_elem)->read_ptr = match_ptr + 1;
	return (1);
}

static size_t		ft_add_buf_lst(char *buffer,
		size_t index, t_list **elem_lst, size_t *num_of_char)
{
	t_list			*new_elem;

	if (index + BUFF_SIZE >= BUFF_SIZE * BUFF_FACTOR - 1)
	{
		new_elem = ft_lstnew(buffer, index + 1);
		if (*elem_lst)
			ft_lstadd_e(elem_lst, new_elem);
		else
			*elem_lst = new_elem;
		*num_of_char += index;
		index = 0;
		*buffer = '\0';
	}
	return (index);
}

static int			ft_reply(t_fd_elem **fd_elem,
		char **line, t_list **elem)
{
	char		*buffer;

	buffer = (*fd_elem)->read_ptr;
	if (*buffer || *elem)
	{
		ft_build_new_line(fd_elem, line, buffer
					+ ft_strlen(buffer), elem);
		return (0);
	}
	else
	{
		*line = ft_strnew(0);
		ft_memdel((void **)(&buffer));
		free(*fd_elem);
		*fd_elem = NULL;
	}
	return (0);
}

static int			ft_read_fd_buffer(t_fd_elem **fd_elem, int fd, char **line,
		t_list **elem)
{
	ssize_t				index;
	ssize_t				ret;
	char				*match_ptr;
	size_t				*num_of_char;
	char				*buffer;

	buffer = ft_strcpy((*fd_elem)->buffer, (*fd_elem)->read_ptr);
	(*fd_elem)->read_ptr = (*fd_elem)->buffer;
	(*fd_elem)->saved_chars = 0;
	num_of_char = &((*fd_elem)->saved_chars);
	index = ft_strlen(buffer);
	while ((ret = read(fd, buffer + index, BUFF_SIZE)) > 0)
	{
		*(char *)(buffer + index + ret) = '\0';
		if ((match_ptr = ft_strchr(buffer + index, '\n')))
			return (ft_build_new_line(fd_elem, line, match_ptr, elem));
		index += ret;
		index = ft_add_buf_lst(buffer, index, elem, num_of_char);
	}
	if (!ret)
		*(buffer + index + 1) = '\0';
	if (ret)
		return (ret);
	return (ft_reply(fd_elem, line, elem));
}

int					ft_get_next_line(const int fd, char **line)
{
	char				*match_ptr;
	t_list				*elem;
	char				*buffer;
	t_fd_elem			**fd_elem;

	elem = NULL;
	if (line)
	{
		fd_elem = ft_get_fd_buf(fd, sizeof(char) * (BUFF_SIZE * BUFF_FACTOR));
		buffer = (*fd_elem)->read_ptr;
		if ((match_ptr = ft_strchr(buffer, '\n')))
			return (ft_build_new_line(fd_elem, line, match_ptr, &elem));
		else
			return (ft_read_fd_buffer(fd_elem, fd, line, &elem));
	}
	return (-1);
}
