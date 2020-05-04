/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Signal communication system
*/

#include <unistd.h>
#include <stdlib.h>
#include "morse.h"

receive_t *g_r;

void	morse_signal_handler(int sig, siginfo_t *info, void *context)
{
	static int b = M_BITS_MAX - 1;
	static int from_pid = 0;
	int pid = info->si_pid;

	if (!from_pid)
		from_pid = pid;
	if (from_pid == pid)
		g_r->buf[b--] = ((sig == M_ZERO) ? '0' : '1');
	if (b <= -1) {
		for (g_r->byte = 0, b++; g_r->buf[b]; g_r->buf[b] = '\0', b++)
			g_r->byte = (g_r->byte << 1) + (g_r->buf[b] - '0');
		g_r->received = 1;
		b--;
		g_r->last_pid = from_pid;
		from_pid = 0;
	}
}

int	wait_for_receive(int timeout)
{
	int value;
	long int cycle_max = (timeout) ? timeout / (M_WAIT * 2) : -1;
	long int cycle;

	for (cycle = 0; !g_r->received; cycle++) {
		if (timeout && cycle >= cycle_max)
			break;
		usleep(M_WAIT * 2);
	}
	g_r->received = 0;
	value = g_r->byte;
	g_r->byte = 0;
	return (value);
}

int	send_morse(int nb, int pid)
{
	int bits;
	int ret;

	ret = kill(pid, 0);
	for (bits = 0; ret == 0 && bits < M_BITS_MAX; bits++) {
		ret = kill(pid, (nb & 1 && nb != 0) ? M_ONE : M_ZERO);
		nb >>= 1;
		usleep(M_WAIT);
	}
	return (ret);
}

void	init_morse_system(void)
{
	struct sigaction signal;
	receive_t *rec;
	int i;

	signal.sa_handler = NULL;
	signal.sa_sigaction = morse_signal_handler;
	signal.sa_flags = M_FLAGS;
	sigemptyset(&signal.sa_mask);
	rec = malloc(sizeof(receive_t));
	rec->byte = 0;
	rec->received = 0;
	rec->buf = malloc(sizeof(char) * (M_BITS_MAX + 1));
	for (i = 0; rec->buf && i <= M_BITS_MAX; rec->buf[i] = '\0', i++);
	rec->last_pid = -1;
	sigaction(M_ZERO, &signal, &(rec->old_sigact_zero));
	sigaction(M_ONE, &signal, &(rec->old_sigact_one));
	g_r = rec;
}

void	destroy_morse_system(void)
{
	if (!g_r)
		return;
	sigaction(M_ZERO, &(g_r->old_sigact_zero), NULL);
	sigaction(M_ONE, &(g_r->old_sigact_one), NULL);
	if (g_r->buf)
		free(g_r->buf);
	free(g_r);
}
