# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpikaliu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/06 14:42:06 by rpikaliu          #+#    #+#              #
#    Updated: 2017/02/18 16:00:21 by rpikaliu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

WWW = -Wall -Wextra -Werror

OBJECTS = ft_printf.o ft_strlen.o ft_putchar.o ft_itoa_base.o ft_atoi.o ft_itoa.o ft_uitoa.o ft_get.o ft_sub.o ft_pr.o ft_putnb.o ft_spec.o ft_prchar.o

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rc $(NAME) $(OBJECTS)

%.o: ./%.c
	gcc $(WWW) -o $@ -c $< -I header.h

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
