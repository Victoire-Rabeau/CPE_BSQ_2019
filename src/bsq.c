/*
** EPITECH PROJECT, 2020
** BSQ
** File description:
** BSQ
*/

#include "bsq.h"

char *get_final_buffer(int *int_buffer, char *char_buffer)
{
    int i = 0;

    for (; int_buffer[i] != -2; i++) {
        if (!int_buffer[i])
            char_buffer[i] = 'o';
        if (int_buffer[i] == -1)
            char_buffer[i] = '\n';
        if (int_buffer[i] == -3)
            char_buffer[i] = 'x';
        if (int_buffer[i] > 0)
            char_buffer[i] = '.';
    }
    char_buffer[i] = '\0';
    my_putstr(char_buffer);
    return char_buffer;
}

int *replace_chars(char *char_buffer, int *int_buffer)
{
    int i = 0;
    int j = 0;

    for (; char_buffer[i] != '\n' && char_buffer[i] != '\0'; i++);
    char_buffer += i + 1;
    for (; char_buffer[j] != '\0'; j++) {
        if (char_buffer[j] == '.')
            int_buffer[j] = 1;
        if (char_buffer[j] == 'o')
            int_buffer[j] = 0;
        if (char_buffer[j] == '\n')
            int_buffer[j] = -1;
    }
    int_buffer[j] = -2;
    return int_buffer;
}

int bsq(int fd, unsigned long long size, int lines_nbr, int len)
{
    char *char_buffer = malloc(sizeof(char) * size + 1);
    int *int_buffer = malloc(sizeof(int) * size + 1);

    if (!char_buffer || !int_buffer)
        return 84;
    char_buffer = read_map(char_buffer, fd, size);
    lines_nbr = get_nbr_lines(char_buffer, size);
    len = size / lines_nbr;
    if (lines_nbr == 1)
        return one_line_map(char_buffer);
    else if (len == 2)
        return one_column_map(char_buffer);
    else {
        int_buffer = replace_chars(char_buffer, int_buffer);
        int_buffer = find_biggest_square(int_buffer, len);
        char_buffer = get_final_buffer(int_buffer, char_buffer);
    }
    free(char_buffer);
    free(int_buffer);
    return 0;
}
