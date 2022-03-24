# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hefernan <hefernan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/17 15:53:44 by hefernan          #+#    #+#              #
#    Updated: 2021/09/15 01:12:33 by hefernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c \
		ft_printdeuxfreres.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_itoa.c \
		ft_itoa_base.c \

OBJ =	ft_printf.o \
		ft_printdeuxfreres.o \
		ft_strdup.o \
		ft_strlen.o \
		ft_itoa.o \
		ft_itoa_base.o \

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) -c $(SRCS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
