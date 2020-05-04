##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	my_printf.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_strcmp.c	\

SRC_H	=	my.h		\
		my_hunter.h	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)
		cp $(NAME) ../
		cp $(SRC_H) ../../include/

clean:
		rm -f $(OBJ)
