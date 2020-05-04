/*
** EPITECH PROJECT, 2018
** navy
** File description:
** Johan | Jeremy
*/

#ifndef NAVY_H_
#define NAVY_H_

#define NAVY_HELP_USAGE		"USAGE:\n     %s [first_player_pid] navy_positions\n"
#define NAVY_HELP_DESC		"DESCRIPTION:\n     %s\n     %s\n"
#define NAVY_HELP_PLAYER_PID	"first_player_pid:  only for the 2nd player. pid of the first player."
#define NAVY_HELP_POSITIONS	"navy_positions:  file representing the positions of the ships."
#define NAVY_MY_PID		"my_pid : %d\n"
#define NAVY_WAIT_FOR_EN	"waiting for enemy connection..."
#define NAVY_EN_CONNECTED	"\n\nenemy connected\n\n"
#define NAVY_CONNECTED		"successfully connected\n\n"
#define NAVY_WRONG_PID		"wrong pid\n\n"
#define NAVY_STR_ATTACK		"attack: "
#define NAVY_STR_WAIT_ATTACK	"waiting for enemy's attack...\n"
#define NAVY_STR_HIT		"hit"
#define NAVY_STR_MISSED		"missed"
#define NAVY_STR_WIN		"I won\n\n"
#define NAVY_STR_EN_WIN		"Enemy won\n\n"
#define NAVY_STR_ERROR		"( error )"
#define NAVY_HIT		20
#define NAVY_MISSED		21
#define NAVY_WIN		22
#define NAVY_OK			255
#define NAVY_NOT		254


typedef struct navy_s {
	int is_server;
	int is_my_turn;
	int en_pid;
	char **my_map;
	char **en_map;
} navy_t;

/* === init.c === */
navy_t	*init_navy(int, char **);
int	connect(navy_t *, int);
int	check_errors(int, char **);
void	free_navy(navy_t *);

/* === game.c ===*/
int     game(navy_t *, char *);
int	wait_for_play(navy_t *);
int	play(navy_t *, char *);
void	display_result(int);

char	**mem_alloc_2d_array(void);
char	**fill_map(void);
int	display_map(navy_t *);
char	**read_map(char *);
int	**get_pos(char *);
int	**mem_2d_int(void);
char	**is_vert(char **, int **, int);
char	**is_hori(char **, int **, int);
char	**put_boats(int **);
void	display_enemy(navy_t *);
int	play_game(navy_t *, char *);
char	*read_attack(char *);
int	attack(navy_t *, int, int);
void	display_en_attack(navy_t *, int, int, int);

#endif
