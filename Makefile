##
## EPITECH PROJECT, 2024
## My_RPG
## File description:
## Makefile
##

NAME		=	my_rpg

SRC			=	$(shell find . -name '*.c')

OBJ			=	$(SRC:.c=.o)

CPPFLAGS	=	-I include/

CFLAGS		=	-W -Wall -Wextra -Werror -g3

LDFLAGS		=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LIBFLAGS	=	-L lib/ -lmy

all:			$(NAME)

$(NAME):		$(OBJ)
		make -C lib/
		gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(LIBFLAGS) -lm

clean:
				make clean -C lib/
		rm -f $(OBJ)
		rm -f *~
		rm -f src/*~
		rm -f include/*~

fclean:			clean
		make fclean -C lib/
		rm -f saves_file/*
		rm -f $(NAME)

re:	fclean all
