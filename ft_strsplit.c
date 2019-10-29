/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:55:33 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/28 08:55:21 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_del(void *content, size_t size)
{
	(void)size;
	free(content);
}

static void		add2lst(size_t index, char *s_ptr, t_list **str_lst,
		size_t *str_count)
{
	char	*sub_str;

	if (index)
	{
		if ((sub_str = ft_strnew(sizeof(*s_ptr) * (index))))
		{
			sub_str = strncpy(sub_str, s_ptr, index);
			if (*str_count)
				ft_lstadd(str_lst, ft_lstnew(sub_str, sizeof(*sub_str) *
							ft_strlen(sub_str)));
			else
				*str_lst = ft_lstnew(sub_str, sizeof(sub_str) *
						ft_strlen(sub_str));
			(*str_count)++;
		}
	}
}

static char		**save2array(size_t str_count, t_list **str_lst)
{
	char		**str_array;
	size_t		index;
	t_list		*elem;

	str_array = (char **)ft_memalloc(sizeof(*str_array) * (str_count + 1));
	if (str_array)
	{
		index = str_count - 1;
		elem = *str_lst;
		while (elem)
		{
			*(str_array + index) = ft_strdup(elem->content);
			elem = elem->next;
			index--;
		}
		*(str_array + str_count) = NULL;
		ft_lstdel(str_lst, &ft_del);
		return (str_array);
	}
	else
		return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	t_list		**str_lst;
	char		*s_ptr;
	char		*match_ptr;
	size_t		str_count;

	str_lst = (t_list **)ft_memalloc(sizeof(*str_lst));
	str_count = 0;
	s_ptr = (char *)s;
	while (s_ptr && *s_ptr)
	{
		if ((match_ptr = ft_strchr(s_ptr, c)))
		{
			add2lst(match_ptr - s_ptr, s_ptr, str_lst, &str_count);
			s_ptr = match_ptr + 1;
		}
		else
		{
			add2lst(ft_strlen(s_ptr), s_ptr, str_lst, &str_count);
			s_ptr = NULL;
		}
	}
	return (save2array(str_count, str_lst));
}
