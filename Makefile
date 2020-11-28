##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPPFLAGS	=	-I./include

SRC		=	src/main.c	\
			src/bsq.c	\
			src/one_line_map.c	\
			src/one_column_map.c	\
			src/reverse_minesweeper.c	\
			src/mark_bigger_square.c

OBJ		=	$(SRC:.c=.o)

NAME		=	bsq

CFLAGS		= 	-Wall -Wextra

MAKE		=	make	

TEST_FLAGS	=	--coverage -lcriterion

all: $(NAME)

lib:
	make -C ./lib/my/

test_run:
	gcc -o $(NAME_TEST) $(CFLAGS) $(SRC_USING_TEST) $(SRC_TEST) -L./lib -lmy $(CPPFLAGS)  $(TEST_FLAGS)
	./$(NAME_TEST)

clean:
	$(MAKE) -C ./lib/my/ clean
	rm -f $(OBJ) *.gcda *.gcno vg* test_Unit lib/libmy.a lib/my/libmy.a

$(NAME):	lib $(OBJ)
		gcc -o $(NAME) $(OBJ) -lmy -L./lib $(CPPFLAGS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re lib test_run
