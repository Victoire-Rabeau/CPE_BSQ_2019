/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** one line buffer
*/

#include "bsq.h"

int one_line_map(char *buffer)
{
    int i = 0;
    int j = 0;

    for (; buffer[i] != '\n' && buffer[i] !='\0'; i++);
    buffer += i + 1;
    for (; buffer[j] != '\0' && buffer[j] == 'o'; j++);
    if (buffer[j] == '.') {
        buffer[j] = 'x';
        j++;
    }
    my_putstr(buffer);
    return 0;
}
