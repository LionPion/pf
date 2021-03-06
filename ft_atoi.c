/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 16:02:35 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/02/18 16:02:39 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

unsigned int	ft_atoi(const char *str)
{
	int r;

	r = 0;
	while (*str != '\0')
	{
		if (*str < 48 || *str > 57)
			return (r);
		r = r * 10 + *str - '0';
		str++;
	}
	return (r);
}
