/*
** EPITECH PROJECT, 2017
** bsq
** File description:
** bsq
*/

#pragma once

typedef struct bsq_s {
	int x;
	int y;
	int max;
} bsq_t;

char *get_first_line(char const *filepath);
int get_number_first_line(char const *filepath);
int count_first_line(char const *filepath);
int count_all_cols(char const *fileath);
char **mem_alloc_2d_array(int row, int cols);
char **do_bsq(char **arr, int row, int col, char const *filepath);
char **mem_alloc_2d_array(int row, int col);
int **mem_2d_int_alloc(int row, int col);
int **placement(int row, int col, char **arr);
int **do_deminer(int **tab, int row, int col, char **arr);
int find_min(int **tab, int i, int j);
bsq_t find_max(int **tab, int i, int j, int max);
bsq_t use_max(int **tab, int row, int col, int max);
char **find_one_row(char **arr, int row, int col, char const *filepath);
char **find_one_col(char **arr, int row, int col, char const *filepath);
