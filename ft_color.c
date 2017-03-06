/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 19:06:01 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/03/05 20:10:14 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

 void    ft_pr_color(int n)
{
	if (n == 1)
		write(1, "\033[22;30m", 8);
	else if (n == 2)
		write(1, "\033[22;31m", 8);
	else if (n == 3)
		write(1, "\033[22;32m", 8);
	else if (n == 4)
		write(1, "\033[22;33m", 8);
	else if (n == 5)
		write(1, "\033[22;34m", 8);
	else if (n == 6)
		write(1, "\033[22;35m", 8);
	else if (n == 7)
		write(1, "\033[22;36m", 8);
	else if (n == 8)
		write(1, "\033[01;30m", 8);
	else if (n == 9)
		write(1, "\033[01;33m", 8);
	else if (n == 10)
		write(1, "\033[01;37m", 8);
	else if (n == 11)
		write(1, "\033[0m", 4);
}

int     ft_find_color(const char *str, t_list *spec)
{
	if (!ft_colcmp(str, "{black}", 7))
		spec->color = 1;
	else if (!ft_colcmp(str, "{red}", 5))
		spec->color = 2;
	else if (!ft_colcmp(str, "{green}", 7))
		spec->color = 3;
	else if (!ft_colcmp(str, "{brown}", 7))
		spec->color = 4;
	else if (!ft_colcmp(str, "{blue}", 6))
		spec->color = 5;
	else if (!ft_colcmp(str, "{magenta}", 9))
		spec->color = 6;
	else if (!ft_colcmp(str, "{cyan}", 6))
		spec->color = 7;
	else if (!ft_colcmp(str, "{gray}", 6))
		spec->color = 8;
	else if (!ft_colcmp(str, "{yellow}", 8))
		spec->color = 9;
	else if (!ft_colcmp(str, "{white}", 7))
		spec->color = 10;
	else if (!ft_colcmp(str, "{eoc}", 5))
		spec->color = 11;
	if (spec->color == 0)
		return (0);
	return (1);
}

int     ft_colcmp(const char *s1, const char *s2, unsigned int n)
{
	unsigned int    i;
	unsigned char   *s11;
	unsigned char   *s22;

	i = 0;
	s11 = (unsigned char*)s1;
	s22 = (unsigned char*)s2;
	while ((s11[i] != '\0' || s22[i] != '\0') && i < n)
	{
		if (s11[i] == s22[i])
			i++;
		else
			return (s11[i] - s22[i]);
	}
	return (0);
}
