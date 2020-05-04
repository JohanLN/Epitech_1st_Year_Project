/*
** EPITECH PROJECT, 2017
** basic_case
** File description:
** basic_case
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "bsq.h"

char **find_one_row(char **arr, int row, int col, char const *filepath)
{
	int i = 0;
	int j = 0;

	for (j = 0; j < col; j++)
		if (arr[0][j] == '.') {
			arr[0][j] = 'x';
			break;
		}
	return (arr);
}

char **find_one_col(char **arr, int row, int col, char const *filepath)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++) {
		if (arr[i][0] == '.') {
			arr[i][0] = 'x';
			break;
		}
	}
	return (arr);
}
