/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:01:23 by jtoty             #+#    #+#             */
/*   Updated: 2019/10/27 17:32:30 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static void			ft_print_result(char const *s)
{
	int		len;

	len = 0;
	while (s[len])
		len++;
	write(1, s, len);
}

static void			ft_result(char const *mem, char const *membis)
{
	ft_print_result(mem);
	write(1, "\n", 1);
	ft_print_result(membis);
}

static int			test_group_1(int case_id)
{
	void	*mem;
	void	*membis;

	if (!(mem = malloc(sizeof(*mem) * 30)))
		return (0);
	memset(mem, 'j', 29);
	((char*)mem)[29] = '\0';
	membis = mem;
	if (case_id == 1)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'r', 20)))
			ft_print_result("NULL");
		else
			ft_result(mem, membis);
	}
	else if (case_id == 2)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'r', 3)))
			ft_print_result("NULL");
		else
			ft_result(mem, membis);
	}
	return (0);
}

static int			test_group_2(int case_id)
{
	void	*mem;
	void	*membis;

	if (!(mem = malloc(sizeof(*mem) * 30)))
		return (0);
	memset(mem, 'j', 29);
	((char*)mem)[29] = '\0';
	membis = mem;
	if (case_id == 3)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvutsrqponmlkjihgfedcba", 'a', 26)))
			ft_print_result("NULL");
		else
			ft_result(mem, membis);
	}
	else if (case_id == 4)
	{
		if (!(mem = ft_memccpy(mem, "zyxwvuzyxwvu", 'x', 20)))
			ft_print_result("NULL");
		else
			ft_result(mem, membis);
	}
	return (0);
}

int					ft_memccpy_test(int case_id)
{
	alarm(5);
	test_group_1(case_id);
	test_group_2(case_id);
	return (0);
}
