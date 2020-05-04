##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC_D	=	./src

SRC_L	=	./lib/my

CFLAGS	=	-I./include -L./lib -lmy

LDFLAGS	=	-W -Wall -Wextra

SRC	=	$(SRC_D)/bsq.c		\
		$(SRC_D)/counter.c	\
		$(SRC_D)/allocation.c	\
		$(SRC_D)/int_array.c	\
		$(SRC_D)/basic_case.c	\

OBJ	=		$(SRC:.c=.o)

NAME	=		bsq

all:		$(NAME)

libmy:
		make -C $(SRC_L)

$(NAME):	$(OBJ) libmy
		gcc -o $(NAME) -g3 $(OBJ) $(CFLAGS) $(LDFLAGS)
		cp $(NAME) test/

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
