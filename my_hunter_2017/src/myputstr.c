/*
** EPITECH PROJECT, 2017
** epitech
** File description:
** str
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_putstr(char const *str)
{
	int e = 0;

	while (str[e] != '\0') {
		my_putchar(str[e]);
		e = e + 1;
	}
	return (0);
}
