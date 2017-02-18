/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 19:12:46 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/18 16:46:31 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_count(uintmax_t n)
{
	int i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	ft_itoa_base_pr(uintmax_t n, char *r, int i)
{
	if (n > 9)
		ft_itoa_base_pr(n / 10, r, i - 1);
	r[i] = n % 10 + '0';
}

char		*ft_uitoa(uintmax_t value)
{
	char	*r;
	int		i;

	i = ft_count(value);
	r = malloc(sizeof(char*) * i);
	r[i--] = '\0';
	ft_itoa_base_pr(value, r, i);
	return (r);
}