/*
** EPITECH PROJECT, 2017
** hunter_function
** File description:
** hunter_function
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_hunter.h"

void poll_event(variable_t *hunter, duck_t *duck)
{
	while (sfRenderWindow_pollEvent(hunter->window, &hunter->event)) {
		if (hunter->event.type == sfEvtMouseButtonPressed) {
			hunter->miss += fail_click(hunter->event, duck,
						hunter->size, hunter->i);
			hunter->score += manage_mouse_click(
				hunter->event, duck, hunter->size);
			my_printf("Well done !\nScore %d\n", hunter->score);
			my_printf("Miss %d\n", hunter->miss);
			duck->speed.x += 0.4;
		}
		if (hunter->event.type == sfEvtClosed || hunter->miss == 2) {
			sfRenderWindow_close(hunter->window);
			my_printf("We should do this again some times!\n");
			my_printf("Final Score = %d\n", hunter->score);
		}
		if (hunter->event.type == sfEvtMouseMoved)
			manage_cursor(hunter->event.mouseMove, hunter);
	}
}

void manage_mouve(variable_t *hunter, duck_t *duck)
{
	if (duck->tick == 10) {
		hunter->i++;
		duck->tick = 0;
		duck->move += 110;
		hunter->rect.left += 110;
		if (hunter->rect.left == 330)
			hunter->rect.left = 0;
	}
}

void call_function(variable_t *hunter, duck_t *duck)
{
	while (sfRenderWindow_isOpen(hunter->window)) {
		poll_event(hunter, duck);
		duck->tick++;
		manage_mouve(hunter, duck);
		duck->pos.x += duck->speed.x;
		duck->pos.y += duck->speed.y;
		rotate_duck(duck);
		sfRenderWindow_clear(hunter->window, sfBlack);
		sfSprite_setTextureRect(duck->sprite, hunter->rect);
		sfRenderWindow_drawSprite(hunter->window, hunter->sprite, NULL);
		sfRenderWindow_drawSprite(hunter->window, duck->sprite, NULL);
		sfRenderWindow_drawSprite(hunter->window, hunter->reticule,
					NULL);
		sfSprite_setPosition(duck->sprite, duck->pos);
		sfRenderWindow_display(hunter->window);
	}
}
