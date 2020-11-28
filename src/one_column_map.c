/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** one column map
*/

#include "bsq.h"

int one_column_map(char *buffer)
{
    int i = 0;
    int j = 0;

    for (; buffer[i] != '\n'; i++);
    buffer += i + 1;
    for (; buffer[j] && (buffer[j] == 'o' || buffer[j] == '\n'); j++);
    if (buffer[j] == '.')
        buffer[j] = 'x';
    my_putstr(buffer);
    return 0;
}
