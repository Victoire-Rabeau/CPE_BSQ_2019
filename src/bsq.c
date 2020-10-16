/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** bsq
*/

#include "bsq.h"

static uchar get_informations(square_t *square, char *filename)
{
    get_size_file(filename, square);
    square->char_buff = malloc(sizeof(char) * (square->file_size + 1));
    square->int_buff = malloc(sizeof(int) * (square->file_size + 1));
    if (!square->char_buff || !square->int_buff)
        return 84;
    get_nbr_lines(square);
}

uchar bsq(char *filename)
{
    square_t *square = init_square();

    if ((square->fd = open(filename, O_RDONLY)) == -1) {
        my_putstr("Can't open the file\n");
        return 84;
    }
    if (get_informations(square, filename))
        return 84;
    return 0;
}