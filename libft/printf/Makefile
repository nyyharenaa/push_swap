# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ny-handr <ny-handr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/21 08:40:56 by ny-handr          #+#    #+#              #
#    Updated: 2026/02/28 11:57:38 by ny-handr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc

CFLAGS=-Wall -Wextra -Werror

RM=rm -f

NAME=libftprintf.a

SRCS=	ft_printf.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_putnbr.c\
		ft_putnbr_hex.c\
		ft_putptr.c\
		ft_putnbr_uns.c\

OBJS=$(SRCS:.c=.o)

all:$(NAME)

$(NAME):$(OBJS)
	ar rcs $@ $^

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJS)

fclean:clean
	$(RM) $(NAME)

re: fclean all
