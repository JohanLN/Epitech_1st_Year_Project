/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Initialisation functions
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "my.h"
#include "navy.h"
#include "morse.h"

void	free_navy(navy_t *navy)
{
	if (navy && navy->my_map) {
		for (int i = 0; i < 9; free(navy->my_map[i]), i++);
		free(navy->my_map);
	}
	if (navy && navy->en_map) {
		for (int i = 0; i < 9; free(navy->en_map[i]), i++);
		free(navy->en_map);
	}
	if (navy)
		free(navy);
	destroy_morse_system();
}

int	check_errors(int ac, char **av)
{
	if (ac > 3 || ac <= 1)
		return (1);
	if (ac == 3 && !my_str_isnum(av[1]))
		return (1);
	return (0);
}

int	connect(navy_t *navy, int pid)
{
	int n = 255;

	init_morse_system();
	my_printf(NAVY_MY_PID, getpid());
	if (navy->is_server) {
		my_printf(NAVY_WAIT_FOR_EN);
		n = wait_for_receive(0);
		send_morse(n, g_r->last_pid);
		my_printf(NAVY_EN_CONNECTED);
		return (g_r->last_pid);
	}
	else {
		send_morse(n, pid);
		n = wait_for_receive(M_TIMEOUT);
		my_printf((n == 255) ? NAVY_CONNECTED : NAVY_WRONG_PID);
		return ((n == 255) ? pid : -1);
	}
}

navy_t	*init_navy(int ac, char **av)
{
	int pid = (ac == 3) ? my_atoi(av[1]) : -1;
	navy_t *navy;

	if (check_errors(ac, av))
		return (NULL);
	navy = malloc(sizeof(navy_t));
	if (!navy)
		return (NULL);
	navy->is_server = (ac == 3) ? 0 : 1;
	navy->is_my_turn = (ac == 3) ? -1 : 1;
	navy->my_map = put_boats(get_pos(av[ac - 1]));
	navy->en_map = fill_map();
	navy->en_pid = -1;
	if (navy->my_map && navy->en_map)
		navy->en_pid = connect(navy, pid);
	if (navy->en_pid == -1 || !navy->my_map || !navy->en_map) {
		free_navy(navy);
		return (NULL);
	}
	return (navy);
}
