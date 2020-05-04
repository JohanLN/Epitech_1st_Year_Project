##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC_D	=	./src

SRC_L	=	./lib/my

CFLAGS	=	-I./include -L./lib -lmy

LDFLAGS	=	-W -Wall -Wextra -lc_graph_prog

SRC	=	$(SRC_D)/my_hunter.c		\
		$(SRC_D)/hit_box.c		\
		$(SRC_D)/hunter_function.c	\
		$(SRC_D)/rules.c		\
		$(SRC_D)/manage_cursor.c	\

OBJ	=		$(SRC:.c=.o)

NAME	=		my_hunter

all:		$(NAME)

libmy:
		make -C $(SRC_L)

$(NAME):	$(OBJ) libmy
		gcc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
