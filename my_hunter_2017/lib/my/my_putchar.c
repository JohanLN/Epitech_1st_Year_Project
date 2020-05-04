/*
** EPITECH PROJECT, 2017
** my_putchar
** File description:
** Display a character on the screen
*/

#include <unistd.h>

int my_putchar(char c)
{
	int i = 1;

	write(1, &c, 1);
	return (i);
}
