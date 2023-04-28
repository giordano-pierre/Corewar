/*
** EPITECH PROJECT, 2022
** day05 task06
** File description:
** prime number ?
*/

int my_is_prime(int nb)
{
    int x = 2;
    if (nb == 0 || nb == 1 || nb < 0) {
        return (0);
    }
    while (x < nb) {
        if (nb % x == 0)
            return (0);
        x++;
    }
    return (1);
}
