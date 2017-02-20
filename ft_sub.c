/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:45:21 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/20 15:47:35 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_subitoa_base_pr(uintmax_t n, t_list *spec)
{
	int		base;

	base = (spec->con == 'o' || spec->con == 'O' ? 8 : 16);
	if (spec->minus == 0 && spec->zero == 0)
		ft_width(ft_strlen(ft_itoa_base(n, base)), spec, n);
	if (spec->hash && base == 8 && (n || spec->precision != -1)
			&& ft_strlen(ft_itoa_base(n, base)) >= spec->precision)
		write(1, "0", 1);
	else if ((spec->hash == 1 && spec->con == 'x' && n != 0)
			|| spec->con == 'p')
		write(1, "0x", 2);
	else if (spec->hash == 1 && base == 16 && spec->con == 'X' && n != 0)
		write(1, "0X", 2);
	if (spec->minus == 0 && spec->zero == 1)
		ft_width(ft_strlen(ft_itoa_base(n, base)), spec, n);
	if (ft_strlen(ft_itoa_base(n, base)) < spec->precision)
		ft_precision(spec, ft_strlen(ft_itoa_base(n, base)));
	if (!(n == 0 && spec->precision == 0))
		ft_itoa_base_pr(n, spec->con, base);
	if (spec->minus == 1)
		ft_width(ft_strlen(ft_itoa_base(n, base)), spec, n);
}

void		ft_usubnbr(uintmax_t nb, t_list *spec)
{
	int a;

	a = nb == 0 ? 0 : 1;
	if (spec->minus == 0 && spec->zero == 0)
		ft_width(ft_strlen(ft_uitoa(nb)), spec, a);
	else if (spec->plus == 1)
		ft_putchar('+');
	if (spec->minus == 0 && spec->zero == 1)
		ft_width(ft_strlen(ft_uitoa(nb)), spec, a);
	if (ft_strlen(ft_uitoa(nb)) < spec->precision)
		ft_precision(spec, ft_strlen(ft_uitoa(nb)));
	if (!(nb == 0 && spec->precision == 0))
		ft_ulputnbr(nb);
	if (spec->minus == 1)
		ft_width(ft_strlen(ft_uitoa(nb)), spec, a);
}

void		ft_subnbr(intmax_t nb, t_list *spec)
{
	intmax_t	n;
	int			k;

	k = nb < 0 ? -1 : 1;
	k = nb == 0 ? 0 : k;
	n = nb < 0 ? -nb : nb;
	if (spec->space == 1 && spec->plus == 0 && nb >= 0)
	{
		write(1, " ", 1);
		spec->i++;
	}
	if (spec->minus == 0 && spec->zero == 0)
		ft_width(ft_strlen(ft_uitoa(n)), spec, k);
	if (nb < 0)
		ft_putchar('-');
	else if (nb >= 0 && spec->plus == 1)
		ft_putchar('+');
	if (spec->minus == 0 && spec->zero == 1)
		ft_width(ft_strlen(ft_uitoa(n)), spec, k);
	if (ft_strlen(ft_uitoa(n)) < spec->precision)
		ft_precision(spec, ft_strlen(ft_uitoa(n)));
	if (!(nb == 0 && spec->precision == 0))
		ft_ulputnbr(n);
	if (spec->minus == 1)
		ft_width(ft_strlen(ft_uitoa(n)), spec, k);
}
