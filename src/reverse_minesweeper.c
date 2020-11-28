/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** reverse mineswipper
*/

#include "bsq.h"

int get_smaller_nbr(int nb1, int nb2, int nb3)
{
    int save = 1;

    if (nb1 <= nb2 && nb1 <= nb3)
        save = nb1;
    if (nb2 < nb1 && nb2 <= nb3)
        save = nb2;
    if (nb3 < nb1 && nb3 < nb2)
        save = nb3;
    save ++;
    return save;
}

static int my_if(int *buffer, int i, int len)
{
    int nb1 = buffer[i - 1];
    int nb2 = buffer[i - len];
    int nb3 = buffer[i - len - 1];
    if (nb3 == -1)
        return 1;
    return get_smaller_nbr(nb1, nb2, nb3);
}

int *find_biggest_square(int *buffer, int len)
{
    int i = 0;

    for (; buffer[i] != -1; i++);
    i += 2;
    for (; buffer[i] != -2; i++) {
        if (buffer[i] == 0 || buffer[i] == -1)
            continue;
        else {
            buffer[i] = my_if(buffer, i, len);
        }
    }
    buffer = mark_bigger_square(buffer, len);
    return buffer;
}
