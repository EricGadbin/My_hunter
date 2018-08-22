/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** events
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include "my.h"

void my_mouse(window_t *mainwin, pnj_t *pnj)
{
	for (int i = 0; i != mainwin->i; i++) {
		if (mainwin->mouse.x >= pnj[i].pos.x &&
		mainwin->mouse.x < pnj[i].pos.x + 110 &&
		mainwin->mouse.y >= pnj[i].pos.y &&
		mainwin->mouse.y < pnj[i].pos.y + 110) {
			pnj[i].pos.x = 0;
			pnj[i].pos.y = rand()%500;
			mainwin->up += 1;
		}
	sfSprite_setPosition(pnj[i].sprite, pnj[i].pos);
	}
}

void analyse_events(window_t *mainwin, pnj_t *pnj, scope_t *scope)
{
	while (sfRenderWindow_pollEvent(mainwin->win, &mainwin->event)) {
		if (mainwin->event.type == sfEvtClosed)
			sfRenderWindow_close(mainwin->win);
		mainwin->mouse = sfMouse_getPositionRenderWindow(mainwin->win);
		if (mainwin->event.type == sfEvtMouseButtonPressed) {
			sfMusic_play(mainwin->sound);
			my_mouse(mainwin, pnj);
			mainwin->ok = 1;
		}
		sfSprite_setPosition(pnj->sprite, pnj->pos);
		if (mainwin->event.type == sfEvtMouseMoved)
			thescope(mainwin->event.mouseMove, scope);
		sfRenderWindow_setMouseCursorVisible(mainwin->win, sfFalse);
	}
}

void setposition(pnj_t *pnj, window_t *mainwin)
{
	for (int i = 0; i != mainwin->i; i++) {
		if (mainwin->up >= pnj[i].b + 10) {
			pnj[i].c += 0.25;
			pnj[i].b += mainwin->up;
		}
		pnj[i].pos.x += pnj[i].speed.x + pnj[i].c;
		pnj[i].pos.y += pnj[i].speed.y;
		if (pnj[i].pos.y > 500)
			pnj[i].speed.y = (-pnj[i].speed.y);
		if(pnj[i].pos.y < 0)
			pnj[i].speed.y = (-pnj[i].speed.y);
		if (pnj[i].pos.x > 1280) {
			mainwin->hp -= 1;
			pnj[i].pos.x = -5;
			}
		}
}

void timeclock(window_t *mainwin, pnj_t *pnj, background_t *back)
{
	sfTime time = sfClock_getElapsedTime(mainwin->clock);
	float seconds = time.microseconds / 1000000.0;

	if (seconds > 0.25) {
		move_rect(pnj, back, mainwin);
		sfClock_restart(mainwin[0].clock);
	}
	setposition(pnj, mainwin);
}

void display(window_t *mainwin, pnj_t *pnj, background_t *back, scope_t *scope)
{
	for (int i = 0; i != mainwin->i; i++)
		sfSprite_setTexture(pnj[i].sprite, pnj[i].text, sfTrue);
	sfSprite_setTexture(back->bcg, back->bcgtext, sfTrue);
	sfSprite_setTexture(back->startsprite, back->starttext, sfTrue);
	sfSprite_setTexture(scope->scopesprite, scope->scopetext, sfTrue);
	while (sfRenderWindow_isOpen(mainwin->win)) {
		timeclock(mainwin, pnj, back);
		for (int i = 0; i != mainwin->i; i++)
			sfSprite_setTextureRect(pnj[i].sprite, pnj[i].rect);
		sfSprite_setTextureRect(back->bcg, back->backrect);
		for (int i = 0; i != mainwin->i; i++)
			sfSprite_setPosition(pnj[i].sprite, pnj[i].pos);
		analyse_events(mainwin, pnj, scope);
		draw(mainwin, pnj, back, scope);
		setscore(mainwin, pnj);
	}
	destroy(mainwin, pnj, back, scope);
}
