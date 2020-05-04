/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** my_atoi function
*/

int	my_atoi(char const *str)
{
	int result = 0;
	int overflow = 1;
	int is_neg = 1;
	int i;

	for (i = 0; str[i] == '-' || str[i] == '+'; i++)
		is_neg *= (str[i] == '-') ? -1 : 1;
	for (i = 0; str[i] >= '0' && str[i] <= '9'; i++) {
		result = (result * 10) + (str[i] - '0');
		overflow = (result < 0) ? 0 : 1;
	}
	return (result * is_neg * overflow);
}
