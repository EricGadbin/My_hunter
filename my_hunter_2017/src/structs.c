/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** structs
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>
#include "my.h"

char *create_map(char *argv)
{
	char *buffer = malloc(sizeof(char) * 616);
	char *filepath = argv;
	int fd = open(filepath, O_RDONLY);
	int size = 1920*1080;
	read(fd, buffer, size);
	close(fd);
	return (buffer);
}

void npc(pnj_t *pnj, window_t *mainwin)
{
	sfIntRect rect = {0, 0, 102, 102};
	sfVector2f speede = {0.5,0.5};
	for (int i = 0; i != mainwin->i; i++) {
		sfVector2f pose = {0,rand()%500};
		pnj[i].pos = pose;
		pnj[i].speed = speede;
		pnj[i].rect = rect;
		pnj[i].sprite = sfSprite_create();
		pnj[i].text = sfTexture_createFromFile("./files/npc.png", NULL);
		pnj[i].a = 0;
		pnj[i].b = 0;
		pnj[i].c = 0;
	}
}

void my_scope(scope_t *scope)
{
	sfVector2f posscope = {0, 0};
	scope->scopepos = posscope;
	scope->scopesprite = sfSprite_create();
	scope->scopetext = sfTexture_createFromFile("./files/a.png", NULL);
}
void win(window_t *mainwin)
{
	sfVector2i mousee = {0, 0};
	sfVideoMode mode = {1278, 780, 32};
	mainwin->mouse = mousee;
	mainwin->mode = mode;
	mainwin[0].music = sfMusic_createFromFile("./files/bad.ogg");
	mainwin->win = sfRenderWindow_create(mainwin->mode, "Win", \
	sfResize | sfClose, NULL);
	mainwin->font = sfFont_createFromFile("./files/ok.ttf");
	mainwin->score = sfText_create();
	mainwin->sound = sfMusic_createFromFile("./files/laser.wav");
	mainwin->up = 0;
	mainwin->lv = 1;
	mainwin->hp = 5;
}

void backg(background_t *back)
{
	sfIntRect backrecte = {0 ,0, 1278, 780};
	back->startsprite = sfSprite_create();
	back->starttext = sfTexture_createFromFile("./files/start.png", NULL);
	back->bcg = sfSprite_create();
	back->bcgtext = sfTexture_createFromFile("./files/Back1.png", NULL);
	back->backrect = backrecte;
}
