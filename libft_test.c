/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:35:37 by jkauppi           #+#    #+#             */
/*   Updated: 2019/10/29 14:41:32 by jkauppi          ###   ########.fr       */
/*                                                                            */
/*  gcc -g -o libft_test libft_test.c ft_memcpy.c ft_memmove.c ft_strstr.c    */
/*  ft_strnstr.c ft_atoi.c ft_isdigit.c ft_isspace.c ft_strlen.c ft_strncmp.c */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

int main()
{
	printf("result is %s  ", memcpy(NULL, NULL, 0));
	printf("  %s\n",      ft_memcpy(NULL, NULL, 0));
	printf("result is %s  ", memcpy(NULL, "STRING", 0));
	printf("  %s\n",      ft_memcpy(NULL, "STRING", 0));
	printf("result is %s  ", memcpy("STRING", NULL, 0));
	printf("  %s\n",      ft_memcpy("STRING", NULL, 0));
	printf("result is %s  ", memcpy(NULL, NULL, 2));
	printf("  %s\n",      ft_memcpy(NULL, NULL, 2));
	printf("result is %s  ", memmove(NULL, NULL, 0));
	printf("  %s\n",      ft_memmove(NULL, NULL, 0));
//	printf("result is %s  ", memmove(NULL, "STRING", 2));
//	printf("  %s\n",      ft_memmove(NULL, "STRING", 2));
//	printf("result is %s  ", memmove("STRING", NULL, 2));
//	printf("  %s\n",      ft_memmove("STRING", NULL, 2));
	printf("result is %s  ", memmove(NULL, NULL, 2));
	printf("  %s\n",      ft_memmove(NULL, NULL, 2));
	printf("Result is %s  ", strstr("MZIRIBMZIRIBMZP", "MZIRIBMZP"));
	printf("  %s\n", ft_strstr("MZIRIBMZIRIBMZP", "MZIRIBMZP"));
	printf("Result is %s  ", strnstr("MZIRIBMZIRIBMZP", "MZIRIBMZP", 14));
	printf("  %s\n", ft_strnstr("MZIRIBMZIRIBMZP", "MZIRIBMZP", 14));
	printf("Result is %s  ", strnstr("MZIRIBMZIRIBMZP", "MZIRIBMZP", 15));
	printf("  %s\n", ft_strnstr("MZIRIBMZIRIBMZP", "MZIRIBMZP", 15));
	printf("Result is %d  ", atoi("9223372036854775807"));
	printf("  %d\n", ft_atoi("9223372036854775807"));
 	printf("Result is %d  ", atoi("-9223372036854775808"));
 	printf("  %d\n", ft_atoi("-9223372036854775808"));
 	printf("Result is %d  ", atoi("9223372036854775808"));
 	printf("  %d\n", ft_atoi("9223372036854775808"));
 	printf("Result is %d  ", atoi("-9223372036854775809"));
 	printf("  %d\n", ft_atoi("-9223372036854775809"));
return (0);
}
