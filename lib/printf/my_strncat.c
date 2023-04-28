/*
** EPITECH PROJECT, 2022
** day07 task01
** File description:
** lib
*/

int my_strlen2(char const *str)
{
    int cpt;
    cpt = 0;
    while (str[cpt] != '\0' || str[cpt] != '\n') {
        cpt++;
    }
    return cpt;
}

char *my_strncat( char *dest , char const *src , int n)
{
    int p = 0;
    int taille = my_strlen2(dest);
    int taille_src = my_strlen2(src);
    if (n > taille + taille_src)
        n = taille + taille_src;
    while (src[p] != '\0' && p <= n - 1) {
        dest[p + taille] = src[p];
        p = p + 1;
    }
    dest[n] = '\0';
    return dest;
}
