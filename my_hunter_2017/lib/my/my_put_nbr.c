/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
	}
	if (nb >= 10)
		my_put_nbr(nb / 10);
	my_putchar('0' + nb % 10);
	return (0);
}
