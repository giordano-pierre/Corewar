/*
** EPITECH PROJECT, 2022
** day07 task01
** File description:
** lib
*/

char *my_strlowcase(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
        i++;
    }
    return str;
}
