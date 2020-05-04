#### Sources
SRC =		./src/my_putchar.c	\
		./src/my_put_nbr.c	\
		./src/my_putstr.c	\
		./src/my_str_isnum.c	\
		./src/my_strncpy.c	\
		./src/my_printf.c	\
		./src/my_atoi.c		\

#### Headers
SRC_I =		./include

#### Make

OBJ =		$(SRC:.c=.o)

NAME =		libmy.a

CFLAGS =	-Wall -Wextra -I$(SRC_I)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)
