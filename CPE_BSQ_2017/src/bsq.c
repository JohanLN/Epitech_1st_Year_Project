/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** BSQ
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "bsq.h"

char **do_bsq(char **arr, int row, int col, char const *filepath)
{
	int size = row * col + 2;
	int fd = open(filepath, O_RDONLY);
	char *buffer = malloc(sizeof(char) * size);
	int i = 0;
	int j = 0;

	read(fd, buffer, count_first_line(filepath));
	int n = read(fd, buffer, size);
	int count = 0;

	buffer[n] = '\0';
	arr = mem_alloc_2d_array(row, col);
	for (count = 0; buffer[count] != '\0'; count++, j++) {
		if (buffer[count - 1] == '\n') {
			j = 0;
			i++;
		}
		arr[i][j] = buffer[count];
	}
	close(fd);
	return (arr);
}

char **do_basic(char **arr, int row, int col, char const *filepath)
{
	bsq_t bsq = { 1, 1, 0 };
	int **tab;

	arr = do_bsq(arr, row, col, filepath);
	tab = placement(row, col, arr);
	bsq = use_max(tab, row, col, bsq.max);
	if (row == 1 && arr[0][0] == 'o')
		find_one_row(arr, row, col, filepath);
	if (col <= 5 && arr[0][0] == 'o')
		find_one_col(arr, row, col, filepath);
	return (arr);
}

char **find_square(char **arr, int row, int col, char const *filepath)
{
	bsq_t bsq = { 1, 1, 0 };
	int **tab;

	arr = do_basic(arr, row, col, filepath);
	tab = placement(row, col, arr);
	bsq = use_max(tab, row, col, bsq.max);
	if (bsq.max == 1 && arr[0][0] == '.'
	|| row == 1 && arr[0][0] == '.' || col <= 5 && arr[0][0] == '.') {
		arr[0][0] = 'x';
		bsq.max = 0;
	}
	if (bsq.max == 1 && arr[0][0] == 'o') {
		find_one_row(arr, row, col, filepath);
		bsq.max = 0;
	}
	for (int i = bsq.y; i != bsq.y - bsq.max; i--) {
		for (int j = bsq.x; j != bsq.x - bsq.max; j--) {
			arr[i][j] = 'x';
		}
	}
	return (arr);
}

int main(int ac, char **av)
{
	char const *filepath = av[1];
	int col = count_all_cols(filepath);
	int row = get_number_first_line(filepath);
	char **arr = find_square(arr, row, col, filepath);

	for (int i = 0; i < row; i++) {
		write(1, arr[i], col - count_first_line(filepath));
		write(1, "\n", 1);
		free(arr[i]);
	}
	free(arr);
}
