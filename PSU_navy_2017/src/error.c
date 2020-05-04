/*
** EPITECH PROJECT, 2018
** error
** File description:
** Jeremy | Johan
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "navy.h"

void manage_error(char *str, int i)
{
	if (i < 1 || i > 2) {
		my_putstr("\nwrong position\n");
		read_attack(str);
	}
	else if (str[0] > 'H' || str[0] < 'A' || str[1] < '1' || str[1] > '8') {
		my_putstr("\nwrong position\n");
		read_attack(str);
	}
}

char *read_attack(char *str)
{
	int red = 0;
	char buff[1];
	int i = 0;

	my_printf(NAVY_STR_ATTACK);
	buff[0] = '\0';
	red = read(STDIN_FILENO, buff, 1);
	if (red == 0)
		return (NULL);
	for (i = 0; buff[0] != '\n' && red != 0; i++) {
		str[i] = buff[0];
		red = read(STDIN_FILENO, buff, 1);
	}
	manage_error(str, i);
	str[i] = '\0';
	return (str);
}
