/*
** EPITECH PROJECT, 2017
** my_hunter
** File description:
** my_hunter
*/

#pragma once

#include <SFML/Graphics/RenderWindow.h>

#define MAN "This is my hunter\n\nYou have to shoot the duck\n\n"
#define MAN2 "Click left to kill them\n\nYou have 2 lifes\n\n"
typedef struct duck {
	int life;
	int move;
	int tick;
	int out;
	sfSprite* sprite;
	sfVector2f pos;
	sfVector2f speed;
} duck_t;

typedef struct variable {
	sfVideoMode mode;
	sfRenderWindow* window;
	sfEvent event;
	sfIntRect rect;
	int size;
	int score;
	int miss;
	sfSprite* sprite;
	sfTexture* ducky;
	sfTexture* background;
	sfTexture* boom;
	int i;
	sfSprite *reticule;
	sfTexture *viseur;
	sfVector2f vector;
	sfVector2f pos;
} variable_t;

int manage_mouse_click(sfEvent event, duck_t *duck, int size);
int fail_click(sfEvent event, duck_t *duck, int size, int i);
duck_t *create_duck(sfTexture* texture, variable_t *hunter);
int hit_box(int x, int y, duck_t *duck, int size);
int miss_target(int x, int y, duck_t *duck, int size);
void create_animation(variable_t *hunter);
void rotate_duck(duck_t *duck);
variable_t *create_hunter(void);
void call_function(variable_t *hunter, duck_t *duck);
void poll_event(variable_t *hunter, duck_t *duck);
void manage_mouve(variable_t *hunter, duck_t *duck);
int flag_h(int ac, char **av);
int play_game(variable_t *hunter, duck_t *duck);
void manage_cursor(sfMouseMoveEvent mouse, variable_t *hunter);
