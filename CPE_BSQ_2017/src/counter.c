/*
** EPITECH PROJECT, 2017
** counter
** File description:
** counter
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int get_number_first_line(char const *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char buffer[200000];
	int i = 0;
	int res = 0;

	read(fd, buffer, 200000);
	while (buffer[i] != '\n') {
		if (buffer[i] >= '0' && buffer[i] <= '9')
			buffer[i] - '0';
		res = my_getnbr(buffer);
		i++;
	}
	close(fd);
	return (res);
}

int count_first_line(char const *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char buffer[200000];
	int i = 0;

	read(fd, buffer, 200000);
	for (i = 0; buffer[i] != '\n'; i++);
	close(fd);
	return (i + 1);
}

int count_all_cols(char const *filepath)
{
	int fd = open(filepath, O_RDONLY);
	char buffer[200000];
	int i = 0;

	read(fd, buffer, 200000);
	for (i = 0; buffer[i] != '\n'; i++);
	for (i += 1; buffer[i] != '\n'; i++);
	close(fd);
	return (i);
}
