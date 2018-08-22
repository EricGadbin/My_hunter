/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** main
*/

#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <stddef.h>
#include "my.h"

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != '\0')
		i++;
	return (i);
}

int document(char **argv)
{
	doc_t doc[0];

	if (argv[1][0] == '-' && argv[1][1] == 'h' && my_strlen(argv[1]) == 2) {
		doc->map = create_map("documentation");
		my_putstr(doc->map);
		free(doc->map);
		return (1);
	}
	return (0);
}

int program(window_t *mainwin, pnj_t *pnj, background_t *back, scope_t *scope)
{
	mainwin->i = 3;
	win(mainwin);
	npc(pnj, mainwin);
	backg(back);
	my_scope(scope);
	mainwin->clock = sfClock_create();
	if (!mainwin->win)
		return (84);
	analyse_events(mainwin, pnj, scope);
	if (mainwin->ok >= 1)
	sfMusic_play(mainwin->music);
	display(mainwin, pnj, back, scope);
	return (0);
}

int main(int ac, char **argv)
{
	int i = 3;
	int a = 0;
	window_t mainwin[1];
	pnj_t pnj[i];
	background_t back[1];
	scope_t scope[1];

	if (ac == 2) {
		document(argv);
		return (0);
	}
	a = program(mainwin, pnj, back, scope);
	if (a != 84)
		return (0);
	else
		return (84);
}
