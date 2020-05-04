/*
** EPITECH PROJECT, 2017
** alloc
** File description:
** alloc
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "bsq.h"

char **mem_alloc_2d_array(int row, int col)
{
	int i = 0;
	char **mem = malloc(sizeof(char *) * (row + 1));

	for (i = 0; i < row; i++)
		mem[i] = malloc(sizeof(char) * (col + 1));
	return (mem);
}

int **mem_2d_int_alloc(int row, int col)
{
	int i = 0;
	int **mem = malloc(sizeof(int *) * (row + 1));

	for (i = 0; i < row; i++)
		mem[i] = malloc(sizeof(int) * (col + 1));
	return (mem);
}
