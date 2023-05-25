/*
** EPITECH PROJECT, 2023
** Corewar
** File description:
** recup_flags
** créer des variables temporaires dans lesquelles si il y'a un -n je le
** stock dans ma structure
** si il y'a un -a je le stocke dans structure et après l'avoir
** stocké je le remets à -1 et ensuite je l'écris dans
** le fichier concernant
** quand je croise un nom de fichier add_tab
*/

#include "../../include/corewar.h"

int dump_flag(char **av, corewar_t *corewar, int i)
{
    if (my_strcmp(av[i], "-dump") == 0) {
        if (av[i + 1] != NULL) {
            corewar->dump = my_getnbr(av[i + 1]);
            if (corewar->dump == -1) {
                write(2, "wrong nbr_cycle.\n", 17);
                return 1;
            }
            // printf("%d\n", corewar->dump);
        }
    }
    return 0;
}

int prog_number_flag(char **av, int i)
{
    int nb_prog = 0;
    if (my_strcmp(av[i], "-n") == 0) {
        if (av[i + 1] != NULL) {
            nb_prog = my_getnbr(av[i + 1]);
            return nb_prog;
            // printf("pro : %d\n", warriors[j]->nb_prog);
        }
    }
    return 0;
}

int load_adress_flag(char **av, int i)
{
    int adress = 0;
    if (my_strcmp(av[i], "-a") == 0) {
        if (av[i + 1] != NULL) {
            adress = my_getnbr(av[i + 1]);
            return adress;
        }
    }
    return 0;
}

int check_file(char **av)
{
    struct stat pln;
    for (int i = 1; av[i] != NULL; i++) {
        if (stat(av[i], &pln) == 0) {
            if (S_ISREG(pln.st_mode) != 0) {
                return 1;
            }
        }
    }
    return 0;
}

int recup_flags(char **av, corewar_t *corewar, champ_t **warriors)
{
    corewar->dump = -1;
    int j = 0;
    for (int i = 1; av[i] != NULL; i++, j++) {
        if (dump_flag(av, corewar, i) != 0)
            return 1;
        int prog_nb = prog_number_flag(av, i);
        int load_adress = load_adress_flag(av, i);
        if (check_file(av) != 0) {
            warriors = add_tab(warriors, load_adress, av[i], prog_nb);
        }
    }
    return 0;
}
