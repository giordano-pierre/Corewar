/*
** EPITECH PROJECT, 2022
** day05 task04
** File description:
** re rec
*/

int my_compute_power_rec (int nb , int p)
{
    if (p == 0) {
        return (1);
    }
    if (p < 0) {
        return (0);
    }
    if (p > 0 ) {
        nb *= my_compute_power_rec (nb ,p - 1);
    } else {
        return (1);
    }
    return (nb);
}
