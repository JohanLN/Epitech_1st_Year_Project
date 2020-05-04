/*
** EPITECH PROJECT, 2017
** manage_cursor
** File description:
** manage_cursor
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_hunter.h"

void manage_cursor(sfMouseMoveEvent mouse, variable_t *hunter)
{
	sfVector2f vector = {mouse.x, mouse.y};

	sfSprite_setPosition(hunter->reticule, vector);
}
