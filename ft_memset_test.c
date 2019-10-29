/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 12:02:51 by jtoty             #+#    #+#             */
/*   Updated: 2019/10/27 17:16:26 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int		test_group_1(int case_id)
{
	void	*mem;

	if (!(mem = malloc(sizeof(*mem) * 15)))
		return (0);
	memset(mem, 'j', 15);
	if (case_id == 1)
	{
		if (mem != ft_memset(mem, 'c', 5))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (case_id == 2)
	{
		if (mem != ft_memset(mem, 'c', 14))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (case_id == 3)
	{
		if (mem != ft_memset(mem, '\n', 6))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	return (0);
}

static int		test_group_2(int case_id)
{
	void	*mem;

	if (!(mem = malloc(sizeof(*mem) * 15)))
		return (0);
	memset(mem, 'j', 15);
	if (case_id == 4)
	{
		if (mem != ft_memset(mem, '\0', 1))
			write(1, "mem's adress was not returned\n", 30);
		write(1, mem, 15);
	}
	else if (case_id == 5)
	{
		if (mem != ft_memset(mem, 0, 0))
			write(1, "mem's adress was not returned\n", 30);
		else
			ft_putendl("OK");
	}
	return (0);
}

static int		test_group_3(int case_id)
{
	void	*mem1;

	if (case_id == 6)
	{
		if (!(mem1 = malloc(sizeof(*mem1) * (9999992147483647ul * 3) + 3)))
			ft_putendl("OK");
		else
			ft_putendl("mem allocation should fail");
	}
	else if (case_id == 7)
	{
		if (!(mem1 = malloc(sizeof(*mem1) * (2147483647u * 2) + 1)))
			ft_putendl("OK");
		else
			ft_putendl("mem allocation should fail");
	}
	return (0);
}

int				ft_memset_test(int case_id)
{
	alarm(5);
	test_group_1(case_id);
	test_group_2(case_id);
	test_group_3(case_id);
	return (0);
}
