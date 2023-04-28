/*
** EPITECH PROJECT, 2022
** day07 task01
** File description:
** lib
*/

int my_str_isnum(char const *str)
{
    int	i = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else
            return (0);
    }
    return (1);
}
