/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** my_putstr
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_putstr(char const *str)
{
	int i;

	if (str == NULL)
		return (84);
	for (i = 0; str[i] != '\0'; i++) {
		my_putchar(str[i]);
	}
	return (0);
}

int print_dot(char const *str)
{
	int i;

	if (str == NULL)
		return (84);
	for (i = 0; str[i] != '\0'; i++) {
		my_putchar(str[i]);
		my_putchar(' ');
	}
	return (0);
}
