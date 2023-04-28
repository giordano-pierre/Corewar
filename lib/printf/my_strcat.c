/*
** EPITECH PROJECT, 2022
** day07 task02
** File description:
** function that concatenates two strings
*/

int my_strlen2(char const *str)
{
    int cpt;
    cpt = 0;
    while (str[cpt] != '\0') {
        cpt++;
    }
    return cpt;
}

char *my_strcat(char *dest, char const *src)
{
    int p;
    int taille = my_strlen2(dest);
    int taille_src = my_strlen2(src);
    for (p = 0; p < taille_src; p++) {
        dest[p + taille] = src[p];
    }
    dest[taille_src + taille] = '\0';
    return dest;
}
