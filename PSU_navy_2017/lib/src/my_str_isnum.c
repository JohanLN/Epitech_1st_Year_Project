/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** str_isnum
*/

int my_str_isnum(char const *str)
{
	int i;

	for (i = 0; str[i] == '-'; i++);
	for ( ; str[i] != '\0'; i++)
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}
