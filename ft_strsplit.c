/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 17:55:33 by jkauppi           #+#    #+#             */
/*   Updated: 2019/11/20 20:13:13 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_save_word(char **array, char *s, int w_len, int w_count)
{
	int		i;

	i = 0;
	array[w_count] = (char *)malloc(sizeof(char) * (w_len + 1));
	while (w_len--)
	{
		array[w_count][i] = *(s - w_len - 1);
		i++;
	}
	array[w_count][i] = '\0';
	return ;
}

static int		ft_count_save(char *s, char c, char **array)
{
	int		w_count;
	int		w_len;

	w_count = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			w_len = 0;
			while (*s && *s != c)
			{
				w_len++;
				s++;
			}
			if (array)
				ft_save_word(array, s, w_len, w_count);
			w_count += 1;
		}
	}
	if (array)
		*(array + w_count) = 0;
	return (w_count);
}

char			**ft_strsplit(char const *s, char c)
{
	int			num_of_words;
	char		**array;

	array = 0;
	num_of_words = ft_count_save((char *)s, c, array);
	array = (char **)malloc(sizeof(*array) * (num_of_words + 1));
	*(array + num_of_words) = 0;
	num_of_words = ft_count_save((char *)s, c, array);
	return (array);
}
