##
## EPITECH PROJECT, 2017
## Makefile
## File description:
##
##

SRC	=	$(wildcard *.c)

SRC_H	=	$(wildcard *.h)

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
		cp $(SRC_H) ../../include/

clean:
		rm -f $(OBJ)
