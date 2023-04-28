/*
** EPITECH PROJECT, 2022
** day07 task01
** File description:
** lib
*/
#include "include/my_printf.h"

int my_sort_swap(int *a, int *b)
{
    if (*a > *b)
        my_swap(a,b);
}

void my_sort_int_array(int *tab, int size)
{
    for (int i = 0; i < size; i++) {
        for (int p = 0; p < size - 1 - i; p++) {
            my_sort_swap(&tab[p], &tab[p + 1]);
        }
    }
}
