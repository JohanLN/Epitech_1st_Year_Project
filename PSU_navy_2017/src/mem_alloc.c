/*
** EPITECH PROJECT, 2018
** mem_alloc
** File description:
** Johan | Jeremy
*/

#include <stdio.h>
#include <stdlib.h>
#include "navy.h"

char **mem_alloc_2d_array(void)
{
	int i;
	int j;
	char **mem = malloc(sizeof(char *) * (8 + 1));

	if (mem == NULL)
		return (NULL);
	for (i = 0; i < 8; i++) {
		mem[i] = malloc(sizeof(char) * (8 + 1));
		for (j = 0; j < 9; mem[i][j] = '\0', j++);
	}
	mem[i] = NULL;
	return (mem);
}

int **mem_2d_int(void)
{
	int i;
	int j;
	int **mem = malloc(sizeof(int *) * (8 + 1));

	if (mem == NULL)
		return (NULL);
	for (i = 0; i < 8; i++) {
		mem[i] = malloc(sizeof(int) * (8 + 1));
		for (j = 0; j < 9; mem[i][j] = 0, j++);
	}
	mem[i] = NULL;
	return (mem);
}
