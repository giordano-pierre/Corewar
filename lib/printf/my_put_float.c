/*
** EPITECH PROJECT, 2022
** snake
** File description:
** put float
*/
#include "include/my_printf.h"
#include <unistd.h>

int my_putchar2(char c)
{
    write(1, &c , 1);
    return 1;
}

int my_float(int number, int count)
{
    if (number < 0) {
    count += my_putchar2('-');
    number = -number;
    }
}

void my_put_float_real(float p_number)
{
int number = p_number;
int devider = 1;
int count = 0;
my_float(number, count);
while (number / devider > 9) {
    devider *= 10;
}
while (devider > 0) {
    count += my_put_nbr((number / devider) % 10);
    devider /= 10;
}
count += my_putchar2('.');
number = p_number * 100.0f;
if (number < 0) {
number = -number;
}
    count += my_put_nbr((number / 10) % 10);
    count += my_put_nbr((number / 1) % 10);
}
