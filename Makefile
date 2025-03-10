# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeschwi <ngeschwi@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/26 12:03:34 by ngeschwi          #+#    #+#              #
#    Updated: 2021/04/26 14:43:45 by ngeschwi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= srcs/ft_printf.c \
			srcs/ft_atoi.c \
			srcs/ft_base_hexa.c \
			srcs/ft_isalpha.c \
			srcs/ft_isdigit.c \
			srcs/ft_itoa.c \
			srcs/ft_print_carac.c \
			srcs/ft_print_check.c \
			srcs/ft_print_hexa.c \
			srcs/ft_print_int.c \
			srcs/ft_print_point.c \
			srcs/ft_putchar.c \
			srcs/ft_putstr.c \
			srcs/ft_strlen.c \
			srcs/ft_utoa.c \
			srcs/ft_reduce_tab.c \
			srcs/ft_print_pc.c \
			srcs/ft_replace_in_text.c \
			srcs/ft_strjoin.c \
			srcs/ft_split.c \
			srcs/ft_strdup.c

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a

CC		= gcc
RM		= rm -f
CFLAGS	= -g3
.c.o:
		${CC} ${CFLAGS} -c -I./includes $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
		ar rcs $(NAME) $(OBJS)
$(OBJS):	includes/ft_printf.h

all:		$(NAME)

clean:
		$(RM) $(OBJS)

fclean:		clean
		$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
