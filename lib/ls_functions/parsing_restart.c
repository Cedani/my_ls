/*
** EPITECH PROJECT, 2020
** parsing
** File description:
** parsing
*/

#include "../../include/my_ls.h"
#include "../../include/my_printf.h"

int nb_file(char **argv)
{
    int nb_f = 0;

    for (int i = 1; argv[i]; i += 1)
        if (argv[i][0] != '-')
            nb_f += 1;
    return (nb_f);
}

int nb_flag(char **argv)
{
    int nb_fl = 0;

    for (int i = 1; argv[i]; i += 1)
        if (argv[i][0] == '-')
            nb_fl = i;
    return (nb_fl);
}

char **files_arg(char **argv)
{
    int nb_f = nb_file(argv);
    char **flag_list = NULL;
    char *test = "./";
    int k = 0;

    if (nb_f == 0) {
        flag_list = malloc(sizeof(char *) + 1);
        for (; k < 1; k += 1) {
            flag_list[k] = malloc(sizeof(char) * 3);
            flag_list[k] = my_strcat(flag_list[k], test);
        }
    } else {
        flag_list = malloc(sizeof(char *) * nb_f + 1);
        for (int i = nb_flag(argv) + 1; argv[i]; i += 1) {
            flag_list[k] = malloc(sizeof(char) * my_strlen(argv[i]));
            flag_list[k] = my_strcat(flag_list[k], argv[i]);
            k += 1;
        }
    }
    flag_list[k] = NULL;
    return (flag_list);
}