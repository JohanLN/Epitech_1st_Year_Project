/*
** EPITECH PROJECT, 2017
** my_printf
** File description:
** my_printf
*/

#include <stdarg.h>
#include <stddef.h>
#include "my.h"

int basic_functions(char *s, int i, va_list list)
{
	if (s[i + 1] == 's')
		my_putstr(va_arg(list, char *));
	else if (s[i + 1] == 'd' || s[i + 1] == 'i')
		my_put_nbr(va_arg(list, int));
	else if (s[i + 1] == 'c')
		return (0);
}

int my_printf(char *s, ...)
{
	va_list list;

	va_start(list, s);
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == '%') {
			basic_functions(s, i, list);
			i++;
		}
		else
			my_putchar(s[i]);
	}
	va_end(list);
	return (0);
}
