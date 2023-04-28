/*
** EPITECH PROJECT, 2022
** day05 task7
** File description:
** number prime ? str
*/
#include "include/my_printf.h"

int my_find_prime_sup(int nb)
{
    int x = nb++;
    while (! my_is_prime(x))
        x++;
    return (x);
}
