/*
** EPITECH PROJECT, 2018
** morse
** File description:
** header file
*/

#ifndef MORSE_H_
#define MORSE_H_

#include <signal.h>

/*
**	Config
*/

//	M_BITS_MAX	8	-> Send & Receive value from 0 to 255
#define M_BITS_MAX	8
//	M_TIMEOUT-> Wait for receive timeout (Default : 1 000 000 = 1s)
#define M_TIMEOUT	1000000
//	M_WAIT	10000	-> Wait 10000 µseconds between each bit send (MINIMUM)
#define M_WAIT		10000
//	M_ZERO		SIGUSR1	-> Signal used to send bit value zero
#define M_ZERO		SIGUSR1
//	M_ONE		SIGUSR2	-> Signal used to send bit value one
#define M_ONE		SIGUSR2
//	M_FLAGS			-> Flags used to define new signals
#define M_FLAGS         (SA_RESTART | SA_SIGINFO)

/*
**	End of Config
*/

typedef struct receive_s {
	int byte;
	int received;
	char *buf;
	int last_pid;
	struct sigaction old_sigact_zero;
	struct sigaction old_sigact_one;
} receive_t;

extern receive_t *g_r;

/* === morse.c === */
void	init_morse_system(void);
void	destroy_morse_system(void);
int	send_morse(int, int);
int	wait_for_receive(int);
void	morse_signal_handler(int, siginfo_t *, void *);

#endif
