/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** mark bigger square
*/

#include "bsq.h"

int *mark_bigger_square(int *buffer, int len)
{
    int i = 0;
    int max = 0;

    for (int i = 0; buffer[i] != -2; i++) {
        if (buffer[i] > max)
            max = buffer[i];
    }
    for (; buffer[i] != max; i++);
    for (int j = 0; j < max; j++ ){
        for (int k = 0; k < max; k ++)
            buffer[i - k * len] = -3;
        i--;
    }
    return buffer;
}
