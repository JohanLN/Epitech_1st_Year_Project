#### Sources
SRC_D =		./src

SRC =		$(SRC_D)/morse.c		\
		$(SRC_D)/create_map.c		\
		$(SRC_D)/game_interface.c	\
		$(SRC_D)/mem_alloc.c		\
		$(SRC_D)/put_boats.c		\
		$(SRC_D)/read_coord.c		\
		$(SRC_D)/init.c			\
		$(SRC_D)/main.c			\
		$(SRC_D)/game.c			\
		$(SRC_D)/error.c

#### Libs
SRC_L =		./lib
SRC_LI =	./lib/include

#### Header
SRC_I =		./include

#### Make
OBJ = 		$(SRC:.c=.o)

NAME = 		navy

CFLAGS =	-g -Wall -Wextra -I$(SRC_I) -I$(SRC_LI) -L$(SRC_L) -lmy

all:		$(NAME)

libmy:
		make -C $(SRC_L)

$(NAME):	$(OBJ) libmy
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
