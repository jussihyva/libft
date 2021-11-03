/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:09:30 by jkauppi           #+#    #+#             */
/*   Updated: 2021/09/12 09:58:32 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static const char	*find_start_ptr(const char *const str)
{
	const char	*start_ptr;

	start_ptr = str;
	while (ft_isspace(*start_ptr))
		start_ptr++;
	return (start_ptr);
}

static const char	*find_end_ptr(const char *const str)
{
	const char	*end_ptr;

	end_ptr = str;
	if (*end_ptr)
	{
		while (*end_ptr)
			end_ptr++;
		while (ft_isspace(*(end_ptr - 1)))
			end_ptr--;
	}
	return (end_ptr);
}

static char	*create_new_string(
						const char *const start_ptr,
						const char *const end_ptr)
{
	char	*new_str;
	size_t	new_str_len;

	new_str_len = end_ptr - start_ptr;
	new_str = ft_strsub(start_ptr, 0, new_str_len);
	return (new_str);
}

char	*ft_strtrim(char const *s)
{
	const char	*start_ptr;
	const char	*end_ptr;
	char		*new_str;

	if (s)
	{
		start_ptr = find_start_ptr(s);
		end_ptr = find_end_ptr(start_ptr);
		new_str = create_new_string(start_ptr, end_ptr);
	}
	else
		new_str = NULL;
	return (new_str);
}
