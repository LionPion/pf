/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 17:54:04 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/20 21:47:10 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_w(const char *str, t_list *spec, int i, va_list ap)
{
	while ((str[i] > 47 && str[i] < 58) || str[i] == '*')
	{
		if ((str[i] > 47 && str[i] < 58))
		{
			spec->width = ft_atoi(&str[i]);
			while ((str[i] > 47 && str[i] < 58))
				i++;
		}
 		else
		{
			spec->width = va_arg(ap, int);
			spec->minus = spec->width < 0 ? 1 : spec->minus;
 			spec->width = spec->width < 0 ? -(spec->width) : spec->width;
			i++;
		}
	}
	return (i);
}

void	ft_baks(va_list ap, va_list tmp, int i)
{
	va_copy(ap, tmp);
	while (--i)
		va_arg(ap, int);
}

void	ft_get_baks(const char *str, t_list *spec)
{
	int i;

	i = 0;
	while (str[i] != 's' && str[i] != 'S' && str[i] != 'p' && str[i] != 'd' &&
			str[i] != 'i' && str[i] != 'D' && str[i] != 'o' && str[i] != 'O' &&
			str[i] != 'u' && str[i] != 'U' && str[i] != 'x' && str[i] != 'X' &&
 			str[i] != 'c' && str[i] != 'C' && str[i] != '%' && str[i] != 'Z')
	{
		if (str[i] == '$')
			spec->baks = ft_atoi(str);
		i++;
	}
}

void	ft_bzero(t_list *spec)
{
	spec->baks = 0;
	spec->plus = 0;
	spec->minus = 0;
	spec->space = 0;
	spec->hash = 0;
	spec->zero = 0;
	spec->width = 0;
	spec->precision = -1;
	spec->modify = 0;
	spec->con = 0;
}
