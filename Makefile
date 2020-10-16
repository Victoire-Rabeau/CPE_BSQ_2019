##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CPPFLAGS	=	-I./include

SRC		=	src/main.c					\
			src/bsq.c					\
			src/struct/init_struct.c	\
			src/file.c

OBJ		=	$(SRC:.c=.o)

NAME		=	bsq

CFLAGS		= 	-Wall -Wextra


all: $(NAME)

lib:
	make -C ./lib

clean:
	make -C ./lib clean
	rm -f $(OBJ) vgcore* *.a

$(NAME):	lib $(OBJ)
		gcc -o $(NAME) $(OBJ) -lmy -L. $(CPPFLAGS)

vg:	CFLAGS += -g3
vg:	fclean $(NAME)

fclean:	clean
	rm -f $(NAME)

re:	fclean all lib

.PHONY: all clean fclean re lib
