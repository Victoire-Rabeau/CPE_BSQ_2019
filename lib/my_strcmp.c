/*
** EPITECH PROJECT, 2020
** minishell1
** File description:
** minishell1
*/

#include <stdbool.h>
#include <stddef.h>

int my_strlen(char const *str);

bool my_strcmp(char const *s1, char const *s2)
{
    if (s2 == NULL)
        return false;
    if (my_strlen(s1) > my_strlen(s2))
        return false;
    for (int i = 0; s1[i]; i++)
        if (s1[i] != s2[i])
            return false;
    return true;
}
