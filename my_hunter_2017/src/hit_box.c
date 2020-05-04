/*
** EPITECH PROJECT, 2017
** hit_box
** File description:
** hit_box
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <time.h>
#include "my_hunter.h"
#include "my.h"

duck_t *create_duck(sfTexture* texture, variable_t *hunter)
{
	duck_t *duck = malloc(sizeof(duck_t));

	duck->sprite = sfSprite_create();
	sfSprite_setTexture(duck->sprite, texture, sfTrue);
	duck->pos = hunter->pos;
	duck->speed = hunter->vector;
	duck->life = 1;
	duck->tick = 0;
	return (duck);
}

int hit_box(int x, int y, duck_t *duck, int size)
{
	srand(time(NULL));
	int height = 110;
	int width = 110;
	int exit = 0;
	sfVector2f rotate = {1, 1};
	sfVector2f resize = {0, 0};

	if (x < duck->pos.x + height && y < duck->pos.y + width
	&& x > duck->pos.x && y > duck->pos.y) {
		duck->life = 0;
		duck->pos.x = -110;
		duck->pos.y = rand() %500 + 1;
		exit++;
		sfSprite_setOrigin(duck->sprite, resize);
	}
	return (exit);
}

int miss_target(int x, int y, duck_t *duck, int size)
{
	int miss = 0;
	int height = 110;
	int width = 110;

	if (x > duck->pos.x + height || y > duck->pos.y + width
	|| x < duck->pos.x || y < duck->pos.y) {
		miss++;
	}
	return (miss);
}

void rotate_duck(duck_t *duck)
{
	sfVector2f scale = {-1, 1};
	sfVector2f rotate = {1, 1};
	sfVector2f vector = duck->pos;
	sfVector2f resize = {110, 0};

	if (vector.x >= 910) {
		sfSprite_setScale(duck->sprite, scale);
		duck->speed.x *= -1;
		sfSprite_setOrigin(duck->sprite, resize);
	}
	else if (vector.x <= -150) {
		sfSprite_setScale(duck->sprite, rotate);
		duck->speed.x *= -1;
	}
}
