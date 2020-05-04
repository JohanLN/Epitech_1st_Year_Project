/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Main function
*/

#include <stddef.h>
#include "navy.h"
#include "my.h"

static void	display_help(char *prog_name)
{
	my_printf(NAVY_HELP_USAGE, prog_name);
	my_printf(NAVY_HELP_DESC, NAVY_HELP_PLAYER_PID, NAVY_HELP_POSITIONS);
}

int main(int ac, char **av)
{
	navy_t *navy = NULL;
	char str[500] = "";
	int res;

	if (ac > 1 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
		display_help(av[0]);
		return (0);
	}
	else
		navy = init_navy(ac, av);
	if (!navy)
		return (84);
	res = game(navy, str);
	free_navy(navy);
	return (res);
}
