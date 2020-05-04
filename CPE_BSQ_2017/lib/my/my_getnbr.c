/*
** EPITECH PROJECT, 2017
** my_getnbr
** File description:
** my_getnbr
*/

int my_getnbr(char const *str)
{
	int nombre = 0;
	int i = 0;

	while (str[i] != '\0') {
	        if (str[i] >= '0' && str[i] <= '9')
			nombre = (str[i] - '0') + (nombre * 10);
		else if ((str[i] <= '0' || str[i] >= '9') && nombre > 0)
			break;
		i++;
	}
	if (str[0] == '-')
		return ((-1) * nombre);
	else
		return (nombre);

}
