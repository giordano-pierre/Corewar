/*
** EPITECH PROJECT, 2022
** day 4 task03
** File description:
** return one by one the characters of a string
*/

int my_strlen(char const *str)
{
    int cpt;
    cpt = 0;
    while (str[cpt] != '\0') {
        cpt++;
    }
    return cpt;
}
