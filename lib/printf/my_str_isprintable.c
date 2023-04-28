/*
** EPITECH PROJECT, 2022
** day07 task01
** File description:
** lib
*/

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
