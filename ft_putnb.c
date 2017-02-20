/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:44:31 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/18 16:33:48 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void		ft_itoa_base_pr(uintmax_t n, char l, uintmax_t base)
{
	char c;

	if (n > base - 1)
		ft_itoa_base_pr(n / base, l, base);
	if (n % base < 10)
	{
		c = n % base + '0';
		write(1, &c, 1);
	}
	else
	{
		c = n % base + (l == 'X' ? 'A' : 'a') - 10;
		write(1, &c, 1);
	}
}

void		ft_lputnbr(intmax_t nb)
{
	if (nb > 9)
	{
		ft_lputnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
}

void		ft_ulputnbr(uintmax_t nb)
{
	if (nb > 9)
	{
		ft_lputnbr(nb / 10);
		ft_putchar((nb % 10) + '0');
	}
	else
		ft_putchar(nb + '0');
}
