/*
** EPITECH PROJECT, 2020
** my_getnbr
** File description:
** my get nbr
*/

#include <unistd.h>

my_getnbr(char const *str)
{
    int a = 0;
    int neg = 1;
    int nb = 0;

    for (int i = 0; str[i] && (str[i] == '+' || str[i] == '-'); i++)
        if (str[i] == '-')
            neg = -neg;
    for (int i = 0; str[i]; i++) {
        if (str[i] >= '0' && str[i] <= '9' && !a)
            nb = (nb * 10) + (str[i] - '0');
        else if (nb)
            a = 1;
    }
    if (nb > 2147483647 || (-nb) < -2147483647)
        return 0;
    return (nb * neg);
}
