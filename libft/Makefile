NAME		=	libft.a

include src.mk

# **************************************************************************** #

SRC			=	$(addprefix src/, $(SRC_FILES))
OBJ			=	$(SRC:.c=.o)
INC_DIR		=	include
LIBC		=	ar -rcs
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	$(foreach path, $(INC_DIR), -I $(path))
RM			=	rm -f

# **************************************************************************** #

.c.o:
		@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJ)
		@$(LIBC) $(NAME) $(OBJ)
		@echo "$(basename $(NAME)) built successfully."

all:	$(NAME)

clean:
		@$(RM) $(OBJ)
		@echo "Object files for $(NAME) removed."

fclean:	clean
		@$(RM) $(NAME)
		@echo "$(NAME) removed."

re:	fclean all

.PHONY: all clean fclean re .c.o