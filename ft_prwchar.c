/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prchar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:43:45 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/19 20:46:46 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	ft_wlen(int c)
{
	int	i;

	i = 0;
	i = c >= 0 && c < 128 ? 1 : i;
	i = c > 127 && c < 2048 ? 2 : i;
	i = c > 2047 && c < 65536 ? 3 : i;
	i = c > 65535 ? 4 : i;
	return (i);
}

static void	ft_fbin(int a, int b, unsigned char *r)
{
	int i;
	int n;

	n = 240 - (4 - (a == 2 ? 1 : a)) * 16;
	i = 0;
	while (a--)
	{
		r[i] = ((n << (6 * (a))) | (b & (64 * ft_p(64, a) - 1))) >> (6 * (a));
		i++;
		n = 128;
	}
}

static void	ft_dop(t_list *spec, int i)
{
	spec->i += i;
	while (i--)
	{
		if (spec->zero && !spec->minus)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
}

void		ft_wpr(wchar_t *str, unsigned char *r, t_list *spec)
{
	int n;
	int i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (ft_wlen(str[i]) == 1)
			r[n++] = str[i];
		else
		{
			ft_fbin(ft_wlen(str[i]), str[i], &r[n]);
			n += ft_wlen(str[i]);
		}
		i++;
	}
	n = 0;
	while (r[n] && n < (spec->precision != -1 ? spec->precision : n + 1))
		write(1, &r[n++], 1);
}

void		ft_wputstr(wchar_t *str, t_list *spec)
{
	int				i;
	int				n;
	unsigned char	*r;

	i = 0;
	n = 0;
	while (str[i])
		n += ft_wlen(str[i++]);
	r = (unsigned char*)malloc(sizeof(*r) * (n + 1));
	r[n] = '\0';
	if (str)
		n = (spec->precision < n && spec->precision != -1 ?
				spec->precision : n);
	spec->i += n;
	i = spec->width - n;
	n = spec->precision < 6 && spec->precision != -1 ? spec->precision : 6;
	if (spec->minus == 0 && i > 0)
		ft_dop(spec, i);
	if (str)
		ft_wpr(str, r, spec);
	else
		write(1, "(null)", n);
	if (spec->minus == 1 && i > 0)
		ft_dop(spec, i);
}
