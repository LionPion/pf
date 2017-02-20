/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:44:43 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/20 17:41:41 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_dod(t_list *spec, int n)
{
	int q;

	q = spec->width - n;
	spec->i += q;
	while (q--)
	{
		if (spec->zero == 1 && spec->precision == -1 && spec->minus == 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
}

void	ft_width(int i, t_list *spec, int nb)
{
	int		n;

	spec->width = (spec->space == 1 && (spec->con == 'i' || spec->con == 'd')
			? spec->width - 1 : spec->width);
	i = (nb < 0 && spec->con != 'i' && spec->con != 'd'
			&& spec->con != 'D' ? i - 1 : i);
	n = (i > spec->precision ? i : spec->precision);
	n = (nb < 0 || (spec->plus == 1 && (spec->con == 'd' || spec->con == 'i'
					|| spec->con == 'D')) ? n + 1 : n);
	n = ((spec->hash == 1 && (spec->con == 'x' || spec->con == 'X') && nb != 0)
			|| (spec->con == 'p') ? n + 2 : n);
	n = (spec->hash == 1 && (spec->con == 'o' || spec->con == 'O') && nb != 0
			&& ft_strlen(ft_itoa_base(nb, 8)) >= spec->precision ? n + 1 : n);
	n = (nb == 0 && spec->precision == 0 && spec->hash == 0 ? 0 : n);
	spec->i += (spec->con == 'p' && nb == 0 && spec->precision == 0 ? 2 : 0);
	spec->i += ((spec->con == 'x' || spec->con == 'X')
			&& spec->hash == 1 && spec->precision == 0) ? 0 : n;
	if ((spec->width - n) > 0)
		ft_dod(spec, n);
}

void	ft_precision(t_list *spec, int i)
{
	int n;

	n = spec->precision - i;
	if (n > 0)
		while (n--)
			write(1, "0", 1);
}
