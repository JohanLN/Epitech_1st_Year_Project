/*
** EPITECH PROJECT, 2018
** read_map
** File description:
** Johan | Jeremy
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "navy.h"

int error_coord(char *buffer, char **tab, int i)
{
	if (buffer[0] < '2' || buffer[0] > '5')
		return (1);
	else if (buffer[2] > 'H' || buffer[5] > 'H')
		return (1);
	else if (buffer[3] > '8' || buffer[6] > '8')
		return (1);
	else if (tab[i][1] == tab[i][3] && tab[i][2] == tab[i][4])
		return (1);
	return (0);
}

char **read_map(char *filepath)
{
	int fd = (filepath) ? open(filepath, O_RDONLY) : -1;
	char *buffer = (fd != -1) ? malloc(sizeof(char) * 8) : NULL;
	char **tab = (fd != -1) ? mem_alloc_2d_array() : NULL;

	if (fd == -1 || !filepath || !buffer || !tab)
		return (NULL);
	for (int i = 0; i < 4 && tab[i] != NULL; i++) {
		read(fd, buffer, 8);
		tab[i][0] = buffer[0];
		tab[i][1] = buffer[2];
		tab[i][2] = buffer[3];
		tab[i][3] = buffer[5];
		tab[i][4] = buffer[6];
		if (error_coord(buffer, tab, i) == 1)
			return (NULL);
	}
	free(buffer);
	close(fd);
	return (tab);
}

int **get_pos(char *filepath)
{
	int **arr = mem_2d_int();
	char **tab = read_map(filepath);

	if (tab == NULL)
		return (NULL);
	for (int i = 0; i < 8; i++) {
		arr[i][0] = tab[i][0] - '0';
		arr[i][1] = tab[i][1] - 'A';
		arr[i][2] = tab[i][2] - '0' - 1;
		arr[i][3] = tab[i][3] - 'A';
		arr[i][4] = tab[i][4] - '0' - 1;
	}
	for (int i = 0; i < 9; free(tab[i]), i++);
	free(tab);
	return (arr);
}
