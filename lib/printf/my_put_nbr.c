/*
** EPITECH PROJECT, 2022
** put nbr
** File description:
** put nbr
*/
#include "include/my_printf.h"

int	my_put_nbr(int nb)
{
    int nina = 1;
    if (nb == -2147483648)
        my_putstr("-2147483648");
    if (nb < 0) {
        nb = nb * (-1);
        my_putchar('-');
    }
    if (nb >= 0) {
        if (nb >= 10) {
            nina = (nb % 10);
            nb = (nb - nina) / 10;
            my_put_nbr(nb);
            my_putchar(48 + nina);
    } else {
    my_putchar(48 + nb % 10);
    }
    }
}
