/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** draw
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include "my.h"

void move_rect(pnj_t *pnj, background_t *back, window_t *mainwin)
{
	int max_back = 2556;
	int max_value = 408;

	for (int i = 0; i != mainwin->i; i++) {
		pnj[i].rect.top += 102;
		if (pnj[i].rect.top == max_value)
			pnj[i].rect.top = 0;
		}
		if (mainwin->up >= 50) {
			back->backrect.left += 1278;
			if (back->backrect.left == max_back)
				back->backrect.left = 0;
		}
}

void destroy(window_t *mainwin, pnj_t *pnj, background_t *back, scope_t *scope)
{
	sfTexture_destroy(pnj->text);
	for (int i = 0; i != mainwin->i; i++)
		sfSprite_destroy(pnj[i].sprite);
	sfTexture_destroy(back->bcgtext);
	sfSprite_destroy(back->bcg);
	sfTexture_destroy(back->starttext);
	sfSprite_destroy(back->startsprite);
	sfTexture_destroy(scope->scopetext);
	sfSprite_destroy(scope->scopesprite);
	sfText_destroy(mainwin->score);
	sfMusic_destroy(mainwin->sound);
	sfMusic_destroy(mainwin->music);
	sfFont_destroy(mainwin->font);
	sfRenderWindow_destroy(mainwin->win);
}

void thescope(sfMouseMoveEvent event, scope_t *scope)
{
	scope->scopepos.x = event.x -55;
	scope->scopepos.y = event.y - 55;
	sfSprite_setPosition(scope->scopesprite, scope->scopepos);
}

void draw(window_t *mainwin, pnj_t *pnj, background_t *back, scope_t *scope)
{
	sfRenderWindow_clear(mainwin->win, sfBlack);
	sfRenderWindow_drawSprite(mainwin->win, back->bcg, NULL);
	if (mainwin->ok != 1) {
	sfRenderWindow_drawSprite(mainwin->win, back->startsprite, NULL);
	}
	sfRenderWindow_drawSprite(mainwin->win, scope->scopesprite, NULL);
	if (mainwin->ok == 1) {
	for (int i = 0; i != mainwin->i; i++)
		sfRenderWindow_drawSprite(mainwin->win, pnj[i].sprite, NULL);
	sfRenderWindow_drawText(mainwin->win, mainwin->score, NULL);
	}
	sfRenderWindow_display(mainwin->win);
}

char *my_itoa(int nb)
{
	int len = 0;
	char *str;
	int tmp = nb;

	while (tmp > 0) {
		tmp /= 10;
		len++;
	}
	str = malloc(sizeof(*str) * (len + 1));
	str[len] = '\0';
	while (len--) {
		str[len] = nb % 10  + '0';
		nb /= 10;
	}
	return (str);
}

void setscore(window_t *mainwin, pnj_t *pnj)
{
	char *score_str;
	for (int i = 0; i != mainwin->i; i++) {
		if (mainwin->up >= pnj[i].a + 10) {
			mainwin->lv += 0.3;
			pnj[i].a = mainwin->up;
		}
	}
		score_str = my_itoa(mainwin->up);
		sfText_setString(mainwin->score, score_str);
		sfText_setFont(mainwin->score, mainwin->font);
		sfText_setCharacterSize(mainwin->score, 75);
}
