/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** my
*/

#include <sys/stat.h>
#include <dirent.h>
#include <SFML/Graphics.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Audio.h>

#ifndef MY_H_
#define MY_H_

typedef struct window_s {
	sfEvent event;
	sfRenderWindow *win;
	sfVideoMode mode;
	sfMusic *music;
	sfClock *clock;
	sfVector2i mouse;
	sfFont *font;
	sfText *score;
	sfMusic *sound;
	int i;
	int up;
	float lv;
	int hp;
	int ok;
} window_t;

typedef struct scope_s {
	sfVector2f scopepos;
	sfSprite *scopesprite;
	sfTexture* scopetext;
} scope_t;

typedef struct pnj_s {
	sfSprite *sprite;
	sfTexture* text;
	sfIntRect rect;
	int a;
	int b;
	float c;
	sfVector2f pos;
	sfVector2f speed;

} pnj_t;

typedef struct background_s {
	sfSprite *bcg;
	sfTexture *bcgtext;
	sfIntRect backrect;
	sfSprite *startsprite;
	sfTexture *starttext;

}background_t;

typedef struct doc_s {
	char *map;

} doc_t;

void move_rect(pnj_t *, background_t *, window_t *);
void destroy(window_t *, pnj_t *, background_t *, scope_t *);
void draw(window_t *, pnj_t *, background_t *, scope_t *);
void setscore(window_t *, pnj_t *);
void npc(pnj_t *, window_t *);
void win(window_t *);
void backg(background_t *);
void display(window_t *, pnj_t *, background_t *, scope_t *);
void timeclock(window_t *, pnj_t *, background_t *);
void setposition(pnj_t *, window_t *);
void analyse_events(window_t *, pnj_t *, scope_t *);
void my_mouse(window_t *, pnj_t *);
void my_scope(scope_t *);
void thescope(sfMouseMoveEvent, scope_t *);
char *create_map(char *);
void my_putchar(char);
int my_putstr(char const *);
int document(char **);
char *my_itoa(int);
#endif /* MY_H_ */
