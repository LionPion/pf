/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:43:45 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/20 15:24:35 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_pr_pr(t_list *spec)
{
	int	n;

	n = (spec->width > 1 ? spec->width - 1 : 0);
	spec->i += n + 1;
	if (spec->minus == 0)
		while (n--)
			write(1, (spec->zero ? "0" : " "), 1);
	write(1, &(spec->con), 1);
	if (spec->minus == 1)
		while (n--)
			write(1, (spec->zero ? "0" : " "), 1);
}

void		ft_wputchar(char c, t_list *spec)
{
	int i;

	i = spec->width - 1;
	spec->i += i > 0 ? spec->width : 1;
	if (spec->minus == 0)
		while (i-- > 0)
		{
			if (spec->zero == 1)
				write(1, "0", 1);
			else
				write(1, " ", 1);
		}
	ft_putchar(c);
	if (spec->minus == 1)
		while (i-- > 0)
			write(1, " ", 1);
}

static void	ft_dop(t_list *spec, int i)
{
	spec->i += i;
	while (i--)
	{
		if (spec->zero)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
}

void		ft_putstr(char const *s, t_list *spec)
{
	int n;
	int i;

	n = spec->precision < 6 && spec->precision != -1 ? spec->precision : 6;
	if (s)
		n = (spec->precision < ft_strlen(s) && spec->precision != -1 ?
				spec->precision : ft_strlen(s));
	spec->i += n;
	i = spec->width - n;
	if (spec->minus == 0 && i > 0)
		ft_dop(spec, i);
	if (s)
		while (*s && n--)
			write(1, s++, 1);
	else
		write(1, "(null)", n);
	if (spec->minus == 1 && i > 0)
	{
		spec->i += i;
		while (i--)
			write(1, " ", 1);
	}
}
