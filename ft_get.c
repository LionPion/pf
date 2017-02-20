/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:42:19 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/19 14:42:59 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_i(const char *str)
{
	int i;

	i = 1;
	while (str[i] != 's' && str[i] != 'S' && str[i] != 'p' && str[i] != 'd' &&
			str[i] != 'i' && str[i] != 'D' && str[i] != 'o' && str[i] != 'O' &&
			str[i] != 'u' && str[i] != 'U' && str[i] != 'x' && str[i] != 'X' &&
			str[i] != 'c' && str[i] != 'C' && str[i] != '%')
		i++;
	return (i);
}

void	ft_get_con(const char *str, t_list *spec)
{
	if (str[0] == 's' || str[0] == 'S' || str[0] == 'p' || str[0] == 'd' ||
			str[0] == 'i' || str[0] == 'D' || str[0] == 'o' || str[0] == 'O' ||
			str[0] == 'u' || str[0] == 'U' || str[0] == 'x' || str[0] == 'X' ||
			str[0] == 'c' || str[0] == 'C' || str[0] == '%')
		spec->con = str[0];
}

void	ft_get_sm_con(const char *str, t_list *spec)
{
	int i;

	i = 0;
	if (str[i] == 'h' && str[i + 1] == 'h')
		spec->modify = 1;
	else if (str[i] == 'h' && str[i + 1] != 'h')
		spec->modify = 2;
	else if (str[i] == 'l' && str[i + 1] == 'l')
		spec->modify = 3;
	else if (str[i] == 'l' && str[i + 1] != 'l')
		spec->modify = 4;
	else if (str[i] == 'j')
		spec->modify = 5;
	else if (str[i] == 'z')
		spec->modify = 6;
	str += (spec->modify == 1 || spec->modify == 3 ? 2 : 0);
	str += (spec->modify == 2 || spec->modify == 4
			|| spec->modify == 5 || spec->modify == 6 ? 1 : 0);
	ft_get_con(str, spec);
}

void	ft_get_flags(char c, t_list *spec)
{
	if (c == ' ')
		spec->space = 1;
	else if (c == '#')
		spec->hash = 1;
	else if (c == '0')
		spec->zero = 1;
	else if (c == '+')
		spec->plus = 1;
	else if (c == '-')
		spec->minus = 1;
}

void	ft_get_specification(const char *str, t_list *spec)
{
	int i;

	i = 0;
	while (str[i] == '#' || str[i] == '0' || str[i] == ' ' ||
			str[i] == '+' || str[i] == '-')
	{
		ft_get_flags(str[i], spec);
		i++;
	}
	if (str[i] > 47 && str[i] < 58)
	{
		spec->width = ft_atoi(&str[i]);
		while (str[i] > 47 && str[i] < 58)
			i++;
	}
	if (str[i] == '.')
	{
		spec->precision = ft_atoi(&str[i + 1]);
		while ((str[i] > 47 && str[i] < 58) || str[i] == '.')
			i++;
	}
	ft_get_sm_con(&str[i], spec);
}
