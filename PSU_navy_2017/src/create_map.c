/*
** EPITECH PROJECT, 2018
** map
** File description:
** Johan | Jeremy
*/

#include <stdlib.h>
#include "my.h"
#include "navy.h"

char **fill_map(void)
{
	char **map = mem_alloc_2d_array();

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			map[i][j] = '.';
		}
	}
	return (map);
}

int display_map(navy_t *navy)
{
	my_putstr("my positions:\n");
	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	for (int i = 0, j = 1; i < 8; i++, j++) {
		my_put_nbr(j);
		my_putstr("|");
		print_dot(navy->my_map[i]);
		my_putchar('\n');
	}
	my_putchar('\n');
	return (1);
}

void display_enemy(navy_t *navy)
{
	my_putstr("enemy's positions:\n");
	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	for (int i = 0, j = 1; i < 8; i++, j++) {
		my_put_nbr(j);
		my_putstr("|");
		print_dot(navy->en_map[i]);
		my_putchar('\n');
	}
	my_putchar('\n');
}
