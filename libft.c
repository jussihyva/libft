/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtoty <jtoty@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 15:16:21 by jtoty             #+#    #+#             */
/*   Updated: 2019/10/29 07:31:46 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include <string.h>

void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write(1, elem->content, len);
	write(1, "\n", 1);
}

t_list	*ft_map(t_list *elem)
{
	int		i;
	t_list	*new_elem;

	new_elem = ft_lstnew(elem->content, elem->content_size);
	if (!new_elem)
		return (0);
	i = 0;
	while (((char *)new_elem->content)[i])
	{
		((char *)new_elem->content)[i] = 'y';
		i++;
	}
	return (new_elem);
}

int main(int argc, const char *argv[])
{
	int			case_id;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;
	t_list		*list;
	char		str [] = "lorem";
	char		str2 [] = "ipsum";
	char		str3 [] = "dolor";
	char		str4 [] = "sit";
	char		*atoi_str;

	(void)argc;
	(void)argv;
	elem = ft_lstnew(str, sizeof(str));
	elem2 = ft_lstnew(str2, sizeof(str2));
	elem3 = ft_lstnew(str3, sizeof(str3));
	elem4 = ft_lstnew(str4, sizeof(str4));
	alarm(5);
	if (!elem || !elem2 || !elem3 || !elem4)
		return (0);
	elem->next = elem2;
	elem2->next = elem3;
	elem3->next = elem4;
	if (atoi(argv[0]) == 1)
	{
		if (!(list = ft_lstmap(elem, &ft_map)))
			return (0);
		if (list == elem)
			write(1, "A new list is not returned\n", 27);
		while (list)
		{
			ft_print_result(list);
			list = list->next;
		}
	}
	case_id = 8;
	while (--case_id > 0)
	{
		ft_putnbr(case_id);
		ft_putchar(' ');
		ft_memset_test(case_id);
		ft_putchar('\n');
	}
	case_id = 5;
	while (--case_id > 0)
	{
		ft_putnbr(case_id);
		ft_putchar(' ');
		ft_memccpy_test(case_id);
		ft_putchar('\n');
	}
	ft_putendl("ft_atoi");
	atoi_str = ft_strdup("2343:4");
	ft_putnbr(atoi(atoi_str));
	ft_putchar(' ');
	ft_putnbr(ft_atoi(atoi_str));
	ft_putchar('\n');
	ft_putendl("ft_strlcat");
	ft_strlcat_test();
	ft_putendl("ft_strsplit");
	ft_strsplit_test();
	ft_putendl("ft_atoi");
	ft_atoi_test();
	ft_memcpy_test();
	return (0);
}
