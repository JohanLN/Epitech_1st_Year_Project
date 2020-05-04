/*
** EPITECH PROJECT, 2017
** rules
** File description:
** rules
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_hunter.h"

int flag_h(int ac, char **av)
{
	if (ac == 2) {
		if (my_strcmp(av[1], "-h"))
			return (1);
		else
			return (0);
	}
	else if (ac > 2)
		return (0);
}

int play_game(variable_t *hunter, duck_t *duck)
{
	sfVector2f resize = {0.1, 0.1};
	sfVector2f master = {360, 360};

	sfRenderWindow_setFramerateLimit(hunter->window, 60);
	if (!hunter->window)
		return (EXIT_FAILURE);
	sfSprite_setTexture(hunter->sprite, hunter->background, sfTrue);
	sfSprite_setTexture(duck->sprite, hunter->ducky, sfTrue);
	sfSprite_setScale(hunter->reticule, resize);
	sfSprite_setOrigin(hunter->reticule, master);
	sfSprite_setTexture(hunter->reticule, hunter->viseur, sfTrue);
	if (!hunter->ducky || !hunter->background)
		return (EXIT_FAILURE);
	call_function(hunter, duck);
	sfSprite_destroy(hunter->sprite);
	sfTexture_destroy(hunter->ducky);
	sfTexture_destroy(hunter->background);
	sfTexture_destroy(hunter->viseur);
	sfRenderWindow_destroy(hunter->window);
	free(hunter);
	free(duck);
}
