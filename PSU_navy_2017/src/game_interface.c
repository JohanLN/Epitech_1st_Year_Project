/*
** EPITECH PROJECT, 2018
** game_interface
** File description:
** Johan | Jeremy
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "navy.h"

void display_en_attack(navy_t *navy, int x, int y, int status)
{
	if (status == NAVY_HIT || status == NAVY_WIN)
		navy->en_map[y][x] = 'x';
	if (status == NAVY_MISSED)
		navy->en_map[y][x] = 'o';
}

int remain_boats(navy_t *navy)
{
	int i = 0;
	int j = 0;

	for (i = 0, j = 0; i < 8; i += (j == 8) ? 1 : 0) {
		if (navy->my_map[i][j] > '1' && navy->my_map[i][j] < '6')
			return (0);
		j += (j == 8) ? -8 : 1;
	}
	return (1);
}

int attack(navy_t *navy, int x, int y)
{
	int status = 0;

	if (navy->my_map[y][x] >= '2' && navy->my_map[y][x] <= '5') {
		navy->my_map[y][x] = 'x';
		status = NAVY_HIT;
	}
	else if (navy->my_map[y][x] < '2' && navy->my_map[y][x] > '5') {
		navy->my_map[y][x] = 'o';
		status = NAVY_MISSED;
	}
	else if (navy->my_map[y][x] == 'x' || navy->my_map[y][x] == 'o') {
		navy->my_map[y][x] = 'o';
		status = NAVY_MISSED;
	}
	if (remain_boats(navy))
		status = NAVY_WIN;
	return (status);
}
