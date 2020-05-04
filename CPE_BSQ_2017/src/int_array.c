/*
** EPITECH PROJECT, 2017
** int_array
** File description:
** int_array
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "bsq.h"

int **placement(int row, int col, char **arr)
{
	int i = 0;
	int j = 0;
	int **tab = mem_2d_int_alloc(row, col);

	for (i = 0; i < row; i++) {
		for (j = 0; j < col; j++) {
			(arr[i][j] == '.') ? tab[i][j] = 1 : 0;
			(arr[i][j] == 'o') ? tab[i][j] = 0 : 0;
		}
	}
	return (tab);
}

int find_min(int **tab, int i, int j)
{
	int min = tab[i - 1][j];

	if (tab[i][j] == 0)
		return (0);
	if (tab[i][j - 1] < min)
		min = tab[i][j - 1];
	if (tab[i - 1][j - 1] < min)
		min = tab[i - 1][j - 1];
	return (min);
}

bsq_t find_max(int **tab, int i, int j, int max)
{
	bsq_t bsq;

	tab[i][j] += find_min(tab, i, j);
	if (tab[i][j] > max) {
		max = tab[i][j];
		bsq.x = j;
		bsq.y = i;
	}
	bsq.max = max;
	return (bsq);
}

bsq_t use_max(int **tab, int row, int col, int max)
{
	bsq_t bsq = { 1, 1, 0 };
	int i = 1;
	int j = 1;

	for (i = 1; i < row; i++) {
		for (j = 1; j < col; j++) {
			bsq = find_max(tab, i, j, bsq.max);
		}
	}
	return (bsq);
}
