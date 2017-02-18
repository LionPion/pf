/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 15:43:33 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/18 16:11:08 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_pr_di(t_list *spec, va_list ap)
{
	if (spec->modify == 0 && spec->con != 'D')
		ft_subnbr(va_arg(ap, int), spec);
	if (spec->modify == 1 && spec->con != 'D')
		ft_subnbr((char)va_arg(ap, int), spec);
	if (spec->modify == 2 && spec->con != 'D')
		ft_subnbr((short)va_arg(ap, int), spec);
	if (spec->modify == 3 && spec->con != 'D')
		ft_subnbr(va_arg(ap, long long int), spec);
	if (spec->modify == 4 || spec->con == 'D')
		ft_subnbr(va_arg(ap, long int), spec);
	if (spec->modify == 5 && spec->con != 'D')
		ft_subnbr(va_arg(ap, intmax_t), spec);
	if (spec->modify == 6 && spec->con != 'D')
		ft_subnbr(va_arg(ap, size_t), spec);
}

void	ft_pr_u(t_list *spec, va_list ap)
{
	if (spec->modify == 0 && spec->con != 'U')
		ft_usubnbr(va_arg(ap, unsigned int), spec);
	else if (spec->modify == 1 && spec->con != 'U')
		ft_usubnbr((unsigned char)va_arg(ap, unsigned int), spec);
	else if (spec->modify == 2 && spec->con != 'U')
		ft_usubnbr((unsigned short int)va_arg(ap, unsigned int), spec);
	else if (spec->modify == 3 && spec->con != 'U')
		ft_usubnbr(va_arg(ap, unsigned long long int), spec);
	else if (spec->modify == 4 || spec->con == 'U')
		ft_usubnbr(va_arg(ap, unsigned long int), spec);
	else if (spec->modify == 5 && spec->con != 'U')
		ft_usubnbr(va_arg(ap, uintmax_t), spec);
	else if (spec->modify == 6 && spec->con != 'U')
		ft_usubnbr(va_arg(ap, size_t), spec);
}

void	ft_pr_ox(t_list *spec, va_list ap)
{
	if (spec->modify == 0 && spec->con != 'O' && spec->con != 'p')
		ft_subitoa_base_pr(va_arg(ap, unsigned int), spec);
	else if (spec->modify == 1 && spec->con != 'O' && spec->con != 'p')
		ft_subitoa_base_pr((unsigned char)va_arg(ap, unsigned int), spec);
	else if (spec->modify == 2 && spec->con != 'O' && spec->con != 'p')
		ft_subitoa_base_pr((unsigned short int)va_arg(ap, unsigned int), spec);
	else if (spec->modify == 3 && spec->con != 'O' && spec->con != 'p')
		ft_subitoa_base_pr(va_arg(ap, unsigned long long int), spec);
	else if (spec->modify == 4 || spec->con == 'O' || spec->con == 'p')
		ft_subitoa_base_pr(va_arg(ap, unsigned long int), spec);
	else if (spec->modify == 5 && spec->con != 'O' && spec->con != 'p')
		ft_subitoa_base_pr(va_arg(ap, intmax_t), spec);
	else if (spec->modify == 6 && spec->con != 'O' && spec->con != 'p')
		ft_subitoa_base_pr(va_arg(ap, size_t), spec);
}

void	ft_pr(t_list *spec, va_list ap)
{
	if (spec->con == 's' || spec->con == 'S')
		ft_putstr(va_arg(ap, char*), spec);
	else if (spec->con == 'c' || spec->con == 'C')
		ft_wputchar(va_arg(ap, int), spec);
	else if (spec->con == 'd' || spec->con == 'i' || spec->con == 'D')
		ft_pr_di(spec, ap);
	else if (spec->con == 'u' || spec->con == 'U')
		ft_pr_u(spec, ap);
	else if (spec->con == 'o' || spec->con == 'x' || spec->con == 'O'
			|| spec->con == 'X' || spec->con == 'p')
		ft_pr_ox(spec, ap);
	else if (spec->con == '%')
		ft_pr_pr(spec);
	else if (spec->con == 0)
	{
		ft_width(1, spec, 0);
		spec->i--;
	}
}
