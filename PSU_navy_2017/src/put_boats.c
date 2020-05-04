/*
** EPITECH PROJECT, 2018
** put_boats
** File description:
** Johan | Jeremy
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "navy.h"

char **is_vert(char **map, int **arr, int k)
{
	int i = 0;

	if (!map || !(*map) || !arr || !(*arr))
		return (NULL);
	for (i = 0; i < 8; i++) {
		if (i >= arr[k][2] && i <= arr[k][4])
			map[i][arr[k][1]] = arr[k][0] + '0';
	}
	return (map);
}

char **is_hori(char **map, int **arr, int k)
{
	int i = 0;

	if (!map || !(*map) || !arr || !(*arr))
		return (NULL);
	for (i = 0; i < 8; i++) {
		if (i >= arr[k][1] && i <= arr[k][3])
			map[arr[k][2]][i] = arr[k][0] + '0';
	}
	return (map);
}

char **put_boats(int **arr)
{
	char **map = (arr) ? fill_map() : NULL;
	int i = 0;

	if (!map || !(*map) || !arr || !(*arr))
		return (NULL);
	for (i = 0; i < 4; i++) {
		if (arr[i][1] == arr[i][3])
			is_vert(map, arr, i);
		else
			is_hori(map, arr, i);
	}
	for (int i = 0; i < 9; free(arr[i]), i++);
	free(arr);
	return (map);
}
