/*
** EPITECH PROJECT, 2022
** day07 task01
** File description:
** lib
*/

int my_str_islower(char const *str)
{
    int	i;
    i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z')
            i++;
        else
            return (0);
    }
    return (1);
}
