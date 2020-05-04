/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

int	my_atoi(char const *);
int	my_putchar(char);
int	my_putstr(char const *);
int	my_put_nbr(int);
int	my_getnbr(char const *);
int	my_str_isnum(char const *);
int	my_strlen(char *);
char	*my_strncat(char *, char *, int);
void	get_buffer(char *, int);
char	*get_next_line(int);
int	my_printf(char *, ...);
int	is_printable(char, char);
int	count_arg(char *, char);
char	**arg_to_array(char *, char);
char	*my_strncpy(char *, char const *, int);
int	print_dot(char const *);
int     my_printf(char *, ...);

#endif
