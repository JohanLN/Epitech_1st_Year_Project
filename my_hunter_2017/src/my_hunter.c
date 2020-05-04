/*
** EPITECH PROJECT, 2017
** MyHunter
** File description:
** MyHunter
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_hunter.h"

int manage_mouse_click(sfEvent event, duck_t *duck, int size)
{
	return (hit_box(event.mouseButton.x, event.mouseButton.y,
			duck, size));
}

int fail_click(sfEvent event, duck_t *duck, int size, int i)
{
	return (miss_target(event.mouseButton.x,
			event.mouseButton.y, duck, size));
}

void create_animation(variable_t *hunter)
{
	sfVideoMode mode = {800, 600};
	sfIntRect rect = {0, 0, 110, 110};
	sfVector2f vector = {1, 0};
	sfVector2f pos = {-110, 0};

	hunter->mode = mode;
	hunter->rect = rect;
	hunter->vector = vector;
	hunter->pos = pos;
}

variable_t *create_hunter(void)
{
	variable_t *hunter;

	hunter = malloc(sizeof(variable_t));
	create_animation(hunter);
	hunter->window = sfRenderWindow_create(hunter->mode, "MyHunter",
					sfResize | sfClose, NULL);
	hunter->event;
	hunter->sprite = sfSprite_create();
	hunter->size = 1;
	hunter->score = 0;
	hunter->miss = 0;
	hunter->i = 0;
	hunter->ducky = sfTexture_createFromFile("utils/spritesheet.png", NULL);
	hunter->background = sfTexture_createFromFile("utils/background.png",
						NULL);
	hunter->reticule = sfSprite_create();
	hunter->viseur = sfTexture_createFromFile("utils/cursor.png", NULL);
	return (hunter);
}

int main(int ac, char **av)
{
	variable_t *hunter = create_hunter();
	duck_t *duck = create_duck(hunter->ducky, hunter);

	sfRenderWindow_setMouseCursorVisible(hunter->window, 0);
	if (flag_h(ac, av) == 0)
		my_printf("%s%sGOOD LUCK SOLDIER\n", MAN, MAN2);
	else
		play_game(hunter, duck);
	return (EXIT_SUCCESS);
}
