/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:55:33 by jkauppi           #+#    #+#             */
/*   Updated: 2020/07/05 22:59:44 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_save_word(char **array, char **s, char c, int w_count)
{
	int		i;
	int		w_len;

	w_len = 0;
	while (**s && **s != c)
	{
		w_len++;
		(*s)++;
	}
	if (array)
	{
		i = 0;
		array[w_count] = (char *)malloc(sizeof(char) * (w_len + 1));
		while (w_len--)
		{
			array[w_count][i] = *(*s - w_len - 1);
			i++;
		}
		array[w_count][i] = '\0';
	}
	return ;
}

static int		ft_count_save(char *s, char c, char **array)
{
	int		w_count;

	w_count = 0;
	if (*s && *s == c)
	{
		ft_save_word(array, &s, c, w_count);
		w_count += 1;
	}
	while (*s)
	{
		if (*s == c)
			s++;
		ft_save_word(array, &s, c, w_count);
		w_count += 1;
	}
	if (array)
		*(array + w_count) = 0;
	return (w_count);
}

char			**ft_strsplit(char const *s, char c)
{
	int			num_of_words;
	char		**array;

	array = NULL;
	if (s)
	{
		num_of_words = ft_count_save((char *)s, c, array);
		array = (char **)malloc(sizeof(*array) * (num_of_words + 1));
		*(array + num_of_words) = 0;
		num_of_words = ft_count_save((char *)s, c, array);
	}
	return (array);
}
