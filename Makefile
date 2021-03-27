# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jchoi-ro <jchoi-ro@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/08 19:31:32 by jchoi-ro          #+#    #+#              #
#    Updated: 2021/03/19 19:10:42 by jchoi-ro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
LIBFT	=	libft
LIB		=	libft.a
SRCS	=	ft_printf.c \
			src/flags_specifiers.c \
			src/hex_handler.c \
			src/int_handler.c \
			src/percent_handler.c \
			src/ptr_handler.c \
			src/str_handler.c \
			src/u_handler.c \
			src/utilities.c
OBJS	=	$(SRCS:.c=.o)
LIBC	=	ar -rcs
INC		=	includes
CC		=	gcc
FLAGS	=	-Wall -Wextra -Werror
RM		=	rm -f

.c.o:
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) -I $(INC)

$(NAME):	$(OBJS)
		make all -C $(LIBFT)
		cp $(LIBFT)/$(LIB) $(NAME)
		$(LIBC) $(NAME) $(OBJS)

all:	$(NAME)

clean:
		$(RM) $(OBJS)
		make clean -C $(LIBFT)

fclean:	clean
		$(RM) $(NAME)
		make fclean -C $(LIBFT)

re:	fclean all

.PHONY: all clean fclean re .c.o
