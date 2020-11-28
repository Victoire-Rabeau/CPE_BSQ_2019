/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** main
*/

#include "bsq.h"


char *read_map(char *buff, int fd, unsigned long long size)
{
    int len = 0;
    int offset = 0;

    while ((len = read(fd, buff + offset, size - offset)) > 0)
        offset += len;
    buff[offset] = '\0';
    return buff;
}

int get_nbr_lines(char *buffer, unsigned long long size)
{
    char *nbr = malloc(sizeof(char) * size);
    int lines = 0;
    int i = 0;

    for (; buffer[i] != '\n' && buffer[i] != '\0'; i++)
        nbr[i] = buffer[i];
    nbr[i] = '\0';
    lines = my_getnbr(nbr);
    return lines;
}

unsigned long long get_size_map(char *filename)
{
    unsigned long long size = 0;
    struct stat stat_buff;

    stat(filename , &stat_buff);
    size = stat_buff.st_size;
    return size;
}

int main(int ac, char **av)
{
    int fd = 0;
    unsigned long long size = 0;
    int lines_nbr = 0;
    int len = 0;

    if (ac != 2) {
        my_putstr("Invalid number of arguments\n");
        return 84;
    }
    if ((fd = open(av[1], O_RDONLY)) == -1) {
        my_putstr("Error open\n");
        return 84;
    }
    size = get_size_map(av[1]);
    if (size < 1) {
        my_putstr("The map has an invalid size\n");
        return 84;
    }
    return bsq(fd, size, lines_nbr, len);
}
