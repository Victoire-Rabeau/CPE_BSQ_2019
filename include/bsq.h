/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** bsq
*/

#include "my.h"

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BSQ_H_
#define BSQ_H_

typedef unsigned char uchar;

typedef struct square_s
{
    int fd;
    unsigned long long file_size;
    int line_nbr;
    char *char_buff;
    int *int_buff;
} square_t;


square_t *init_square(void);


void get_size_file(char *filename, square_t *square);
void read_file(square_t *square);
void get_nbr_lines(square_t *square);


uchar bsq(char *filename);

#endif /* !BSQ_H_ */

