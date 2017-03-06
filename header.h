/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:12:14 by rpikaliu          #+#    #+#             */
/*   Updated: 2017/03/05 20:41:49 by rpikaliu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <locale.h>
# include <unistd.h>
# include <stdio.h>

typedef struct	s_list
{
	int			baks;
	int			i;
	int			plus;
	int			minus;
	int			space;
	int			hash;
	int			zero;
	int			width;
	int			precision;
	int			modify;
	int			color;
	char		con;
}				t_list;

int				ft_p(int a, int power);
int				ft_i(const char *str);
int				ft_strlen(const char *str);
int				ft_printf(const char *format, ...);
int				ft_find_color(const char *str, t_list *spec);
int				ft_submake(t_list *spec, const char *s, int i);
int				ft_w(const char *str, t_list *spec, int i, va_list ap);
int				ft_colcmp(const char *s1, const char *s2, unsigned int n);

char			*ft_itoa(intmax_t z);
char			*ft_uitoa(uintmax_t z);
char			*ft_itoa_base(uintmax_t value, uintmax_t base);

void			ft_wputstr(wchar_t *s, t_list *spec);
void			ft_putchar(char c);
void			ft_pr_color(int n);
void			ft_pr_pr(t_list *spec);
void			ft_bzero(t_list *spec);
void			ft_lputnbr(intmax_t nb);
void			ft_ulputnbr(uintmax_t nb);
void			ft_pr(t_list *spec, va_list ap);
void			ft_pr_u(t_list *spec, va_list ap);
void			ft_precision(t_list *spec, int i);
void			ft_wputchar(char c, t_list *spec);
void			ft_get_flags(char c, t_list *spec);
void			ft_pr_di(t_list *spec, va_list ap);
void			ft_pr_ox(t_list *spec, va_list ap);
void			ft_subnbr(intmax_t nb, t_list *spec);
void			ft_width(int i, t_list *spec, int nb);
void			ft_usubnbr(uintmax_t nb, t_list *spec);
void			ft_putstr(char const *s, t_list *spec);
void			ft_get_con(const char *str, t_list *spec);
void			ft_baks(va_list ap, va_list tmp, int i);
void			ft_get_baks(const char *str, t_list *spec);
void			ft_get_sm_con(const char *str, t_list *spec);
void			ft_subitoa_base_pr(uintmax_t n, t_list *spec);
void			ft_make(const char *str, va_list ap, t_list *spec);
void			ft_get_specification(const char *str, t_list *spec, va_list ap);
void			ft_itoa_base_pr(uintmax_t n, char l, uintmax_t base);
void			ft_itoa_base_pr(uintmax_t n, char l, uintmax_t base);

unsigned int	ft_atoi(const char *str);

#endif
