/*
** EPITECH PROJECT, 2022
** day03 task02
** File description:
** send the alphabet in inverse z->a
*/
#include "include/my_printf.h"

int my_isneg(int nb)
{
    if (nb < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
}
