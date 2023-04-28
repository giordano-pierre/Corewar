/*
** EPITECH PROJECT, 2022
** day07 task01
** File description:
** lib
*/
#include <unistd.h>
#include "include/my_printf.h"

void my_convertnbr_base_rec(int nbr, char* base, int base_len, char* str)
{
    if (nbr < 0) {
        my_putchar('-');
    } else {
        nbr = - nbr;
    }
    if (nbr <= -base_len) {
        my_convertnbr_base_rec(-(nbr / base_len), base, base_len, str + 1);
    } else {
        str[1] = '\0';
    }
    *str = base[-(nbr % base_len)];
}

void my_putnbr_base(int nbr, char *base)
{
    int len;
    char str[33];
    len = my_strlen(base);
    my_convertnbr_base_rec(nbr, base, len, str);
    my_revstr(str);
    my_putstr(str);
}

int is_printable(char c)
{
    if (c < 32 || c > 127)
        return (0);
    return 1;
}

int my_str_isprintable(char const *str)
{
    int	i = 0;
    if (str == "")
        return 1;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 127)
            return (0);
    i++;
    }
    return 1;
}

int my_showstr(char const *str)
{
    int exit = 1;
    int i = 0;
    while (str[i]) {
        if (my_str_isprintable == 0) exit = 0;
        if (is_printable(str[i])) {
            my_putchar(str[i]);
        } else
            my_putchar('\\');
        if (str[i] < 16)
            my_putchar('0');
        my_putnbr_base(str[i], "0123456789abcdef");
        i++;
    }
    return exit;
}
