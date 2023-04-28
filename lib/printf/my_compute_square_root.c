/*
** EPITECH PROJECT, 2022
** day05 task5
** File description:
** fonction that returns thr quare root of the number given as argument
*/

int my_compute_square_root(int nb)
{
    int x = 0;
    if (nb < 0) {
        return (0);
    }
    if (nb == 0) {
        return (0);
    }
    while (x * x != nb) {
        x++;
        if (x > nb) {
            return (0);
        }
    }
    return (x);
}
