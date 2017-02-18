/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:46:52 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/18 16:07:29 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int		ft_count(intmax_t n)
{
	intmax_t	k;
	int			i;

	i = 0;
	k = n;
	if (n < 0)
	{
		k = -k;
		i++;
	}
	while (k > 9)
	{
		k /= 10;
		i++;
	}
	return (i);
}

static char		*ft_makes(char *r, int i, intmax_t n, intmax_t q)
{
	i++;
	r[i] = '\0';
	i--;
	while (n > 9)
	{
		r[i] = n % 10 + '0';
		i--;
		n /= 10;
	}
	r[i] = n + '0';
	if (q < 0)
		r[0] = '-';
	return (r);
}

char			*ft_itoa(intmax_t z)
{
	char		*r;
	int			i;
	intmax_t	q;
	intmax_t	n;

	n = z;
	q = n;
	i = ft_count(q);
	if (n < 0)
		n = -n;
	r = (char*)malloc(sizeof(*r) * (i + 2));
	if (r)
		return (ft_makes(r, i, n, q));
	return (0);
}
