/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:41:15 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/03/05 20:10:08 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_list	*ft_create_spec(void)
{
	t_list *spec;

	spec = malloc(sizeof(t_list));
	spec->color = 0;
	spec->baks = 0;
	spec->i = 0;
	spec->plus = 0;
	spec->minus = 0;
	spec->space = 0;
	spec->hash = 0;
	spec->zero = 0;
	spec->width = 0;
	spec->precision = -1;
	spec->modify = 0;
	spec->con = 0;
	return (spec);
}

int		ft_i2(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '}')
		i++;
	return (i);
}

int		ft_submake(t_list *spec, const char *s, int i)
{
	if (s[i] == '{' && ft_find_color(&s[i], spec))
	{
		ft_pr_color(spec->color);
		i += ft_i2(&s[i]);
	}
	else
	{
		(spec->i)++;
		write(1, &s[i], 1);
	}
	return (i);
}

void	ft_make(const char *s, va_list ap, t_list *spec)
{
	int		i;
	va_list	tmp;

	i = 0;
	va_copy(tmp, ap);
	while (s[i])
	{
		if (s[i] != '%')
			i = ft_submake(spec, s, i);
		else
		{
			ft_get_specification(&s[i + 1], spec, ap);
			if (spec->baks)
				ft_baks(ap, tmp, spec->baks);
			ft_pr(spec, ap);
			if (spec->con != 0)
			{
				i += ft_i(&s[i]);
			}
			else
				while (s[i + 1] == ' ' || s[i + 1] == '%' || s[i + 1] == 'Z'
	|| s[i + 1] == '.' || s[i + 1] == '*' || (s[i + 1] > 47 && s[i + 1] < 58))
					i++;
			ft_bzero(spec);
		}
		i++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_list	*spec;

	setlocale(LC_ALL, "en_US.UTF-8");
	spec = ft_create_spec();
	va_start(ap, format);
	ft_make(format, ap, spec);
	va_end(ap);
	return (spec->i);
}
