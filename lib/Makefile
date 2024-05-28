##
## EPITECH PROJECT, 2024
## My_RPG
## File description:
## Makefile
##

NAME		=		libmy.a

SRC			=		my_putchar.c		\
					my_putstr.c			\

OBJ			=		$(SRC:.c=.o)

CFLAGS		=		-W -Werror -Wall -Wextra

CPPFLAGS	=		-I./../include

all:				$(NAME)

$(NAME):			$(OBJ)
			ar rc $(NAME) $(OBJ)

clean:
			$(RM) *~
			$(RM) $(OBJ)

fclean:				clean
			$(RM) $(NAME)

re:	fclean all
