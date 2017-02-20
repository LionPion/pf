/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:12:46 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/18 17:04:02 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_count(uintmax_t n, uintmax_t base)
{
	int i;

	i = 1;
	while (n > base - 1)
	{
		n /= base;
		i++;
	}
	return (i);
}

static void	ft_itoa_base_p(uintmax_t n, char *r, int i, uintmax_t base)
{
	if (n > base - 1)
		ft_itoa_base_p(n / base, r, i - 1, base);
	if (n % base < 10)
		r[i] = n % base + '0';
	else
		r[i] = n % base + 'A' - 10;
}

char		*ft_itoa_base(uintmax_t value, uintmax_t base)
{
	char	*r;
	int		i;

	r = malloc(sizeof(char*) * (ft_count(value, base) + 1));
	i = ft_count(value, base);
	r[i--] = '\0';
	ft_itoa_base_p(value, r, i, base);
	return (r);
}
