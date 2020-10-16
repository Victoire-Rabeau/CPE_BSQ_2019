/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** main
*/

#include "bsq.h"

static uchar display_help(void)
{
    my_putstr("USAGE:\n\t./bsq map.txt\n");
    return 0;
}

static uchar check_arguments(int ac, char **av)
{
    if (ac != 2) {
        my_putstr("Invalid number of arguments, 2 expected\n");
        return 84;
    }
    if (my_strcmp("-h", av[1]))
        return display_help();
    return 1;
}

int main(int ac, char **av)
{
    int r = check_arguments(ac, av);

    return (r == 1) ? bsq(av[1]) : r;
}