##
## EPITECH PROJECT, 2019
## project_2019
## File description:
## Project makefile
##

DUT	=	./tests/

SRC	=	main.c			\
		get_next_line.c	\

SRC_UT =	get_next_line.c				\
			$(DUT)test_get_next_line.c

OBJ	=	$(SRC:.c=.o)

NAME	=	EXEC

CFLAGS	+= -Wall -Wextra -I. -g

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) -g

clean:
	rm -f  $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

tests_run:
	gcc -o $(NAME) $(SRC_UT) -I. -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re
