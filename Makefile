##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

LIB		=		./lib/my/my_putstr.c		\
				./lib/my/my_putchar.c	\
				./lib/my/my_put_nbr.c 	\
				./lib/my/my_printf.c 	\
				./lib/my/my_strlen.c 	\
				./lib/my/base.c 			\
				./lib/my/my_revstr.c		\
				./lib/my/my_getnbr.c 	\
				./lib/my/funcs1.c		\
				./lib/my/funcs2.c		\
				./lib/my/funcs3.c 		\
				./lib/my/my_strtol.c	\
				./lib/my/my_strcat.c	\

LS_FUNC	=		./lib/ls_functions/listing.c	\
				./lib/ls_functions/permission.c		\
				./lib/ls_functions/get_time.c		\
				./lib/ls_functions/flag_ls_t.c		\
				./lib/ls_functions/flag_ls_r.c

MAIN	=		main.c		\

SRC		=		$(LIB)	\
				$(LS_FUNC)	\
				$(MAIN)

UNIT 	=		./tests/test.c 	\

OBJ 	= $(SRC:.c=.o)

CC 		= gcc

NAME	=		my_ls

LIBMY	=		./lib/my/libmy.a

all:	$(OBJ)
	ar rc $(LIBMY) $(OBJ)
	$(CC) -g3 -o $(NAME) $(MAIN) $(LIBMY)

tests_run:
	$(CC) -o units $(SRC) $(UNIT) --coverage -lcriterion ./lib/my/libmy.a

clean:
		rm -rf *.gcda
		rm -rf *.gcno
		rm -rf ./lib/my/*.o
		rm -rf ./lib/ls_functions/*.o
		rm -rf *.o

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBMY)
		rm -f units

re: 	fclean all