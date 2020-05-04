/*
** EPITECH PROJECT, 2018
** navy
** File description:
** game algo
*/

#include <unistd.h>
#include "navy.h"
#include "morse.h"
#include "my.h"

void	display_game(navy_t *navy, int bypass)
{
	static int is_printable = 1;

	if (is_printable == 1 || bypass) {
		display_map(navy);
		display_enemy(navy);
	}
	is_printable *= -1;
}

void	display_result(int status)
{
	char *str;

	if (status == NAVY_HIT || status == NAVY_WIN)
		str = NAVY_STR_HIT;
	else if (status == NAVY_MISSED)
		str = NAVY_STR_MISSED;
	else
		str = NAVY_STR_ERROR;
	my_printf("%s\n\n", str);
}

int	play(navy_t *navy, char *str)
{
	char *pos = read_attack(str);
	int status;

	send_morse(pos[0] - 'A', navy->en_pid);
	usleep(M_WAIT * 2);
	wait_for_receive(0);
	usleep(M_WAIT * 2);
	send_morse(pos[1] - '1', navy->en_pid);
	usleep(M_WAIT * 2);
	wait_for_receive(0);
	usleep(M_WAIT * 2);

	status = wait_for_receive(0);
	display_en_attack(navy, pos[0] - 'A', pos[1] - '1', status);
	my_printf("\n%s: ", pos);
	return (status);
}

int	wait_for_play(navy_t *navy)
{
	int pos_x;
	int pos_y;
	int status;

	my_printf(NAVY_STR_WAIT_ATTACK);
	pos_x = wait_for_receive(0);
	send_morse(NAVY_OK, navy->en_pid);
	pos_y = wait_for_receive(0);
	send_morse(NAVY_OK, navy->en_pid);
	status = attack(navy, pos_x, pos_y);
	send_morse(status, navy->en_pid);
	my_printf("%c%c: ", pos_x + 'A', pos_y + '1');
	return (status);
}

int	game(navy_t *navy, char *str)
{
	int status = 0;

	for ( ; status != NAVY_WIN; (navy->is_my_turn) *= (-1)) {
		display_game(navy, 0);
		if (navy->is_my_turn == 1)
			status = play(navy, str);
		else if (navy->is_my_turn == -1)
			status = wait_for_play(navy);
		display_result(status);
	}
	display_game(navy, 1);
	if ((navy->is_my_turn) == -1 && status == NAVY_WIN) {
		my_printf(NAVY_STR_WIN);
		return (0);
	}
	else if (status == NAVY_WIN) {
		my_printf(NAVY_STR_EN_WIN);
		return (1);
	}
	return (84);
}
