##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

SRC		=		main.c 	\



OBJ		=		$(SRC:.c=.o)

NAME	=		my_ls

all:		$(OBJ)
		gcc $(OBJ) -o $(NAME)

clean:
		rm -rf *.o

fclean: clean
		rm -rf *.o
		rm -f $(NAME)

re: 	fclean all