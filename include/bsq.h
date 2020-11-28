/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** bsq_functions
*/

#include "my.h"

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BSQ_FUNCTONS_H_
#define BSQ_FUNCTONS_H_

char *read_map(char *buff, int fd, unsigned long long size);
int get_nbr_lines(char *buffer, unsigned long long size);
int *replace_chars(char *char_buffer, int *int_buffer);
int one_line_map(char *buffer);
int one_column_map(char *buffer);
int *find_biggest_square(int *buffer, int len);
int *mark_bigger_square(int *buffer, int len);
int bsq(int fd, unsigned long long size, int lines_nbr, int len);

#endif /* !BSQ_FUNCTIONS_H_ */
