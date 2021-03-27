NAME		=	libftprintf.a

include	src.mk

# **************************************************************************** #

SRC			=	$(addprefix src/, $(SRC_FILES))
OBJ			=	$(SRC:.c=.o)
INC_DIR		=	include libft/include
LIBC		=	ar -rcs
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(foreach path, $(INC_DIR), -I $(path))
RM			=	rm -f

# **************************************************************************** #

.c.o:
		@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
		@make all -C libft -s
		@cp libft/libft.a $(NAME)
		@$(LIBC) $(NAME) $(OBJ)
		@echo "$(basename $(NAME)) built successfully."

all:	$(NAME)

clean:
		@$(RM) $(OBJ)
		@echo "Object files for $(NAME) removed."
		@make clean -C libft -s

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(NAME) removed."
		@make fclean -C libft -s

re:	fclean all

.PHONY: all clean fclean re .c.o
