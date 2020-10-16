/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** file
*/

#include "bsq.h"

void get_size_file(char *filename, square_t *square)
{
    struct stat stat_buff;

    stat(filename , &stat_buff);
    square->file_size = stat_buff.st_size;
}

void read_file(square_t *square)
{
    int len = 0;
    int offset = 0;

    for (; (len = read(square->fd, square->char_buff + offset,
        square->file_size - offset)) > 0; offset += len);
    square->char_buff[offset] = '\0';
}

void get_nbr_lines(square_t *square)
{
    square->line_nbr = my_getnbr(square->char_buff);

    printf("line_nbr: %d\n", square->line_nbr);
    /*char *nbr = malloc(sizeof(char) * square->file_size);
    int lines = 0;
    int i = 0;

    for (; square->char_buff[i] != '\n' && square->char_buff[i] != '\0'; i++)
        nbr[i] = square->char_buff[i];
    nbr[i] = '\0';
    lines = my_getnbr(nbr);
    return lines;*/
}
