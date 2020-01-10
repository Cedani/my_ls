/*
** EPITECH PROJECT, 2020
** parsing.c
** File description:
** parsing
*/

#include "../../include/my_ls.h"
#include "../../include/my_printf.h"

int parsing_argument(int argc, char **argv)
{
    t_file *list = NULL;
    int i = 0;

    if (argc == 1) {
        list = file_list("./", &i);
        my_ls(list, i);
        return (0);
    }
    if (argc == 2 && argv[1][0] != '-') {
        if (test_exist(argv[1], OFF) == 1) {
            list = file_list(argv[1], &i);
            my_ls(list, i);
        }
        return (0);
    }
    parsing_flag(argc, argv);
}

void parsing_flag(int argc, char **argv)
{
    int f_r = 0;
    int f_l = 0;
    int f_t = 0;
    FLAG flag_l = OFF;
    FLAG flag_t = OFF;

    for (int i = 1; argv[i] && argv[i][0] == '-'; i += 1) {
        for (int j = 0; argv[i][j]; j += 1) {
            if (argv[i][j] == 'l')
                f_l += 1;
            if (argv[i][j] == 't')
                f_t += 1;
            if (argv[i][j] == 'R')
                f_r += 1;
        }
    }
    flag_l = f_l > 0 ? ON : OFF;
    flag_t = f_t > 0 ? ON : OFF;
    launch_functions(argv, flag_l, flag_t, f_r);
}

int launch_functions(char **argv, FLAG flag_l, FLAG flag_t, int f_r)
{
    int size = 0;
    int i = 0;
    t_file *list = NULL;
    char **tab = files_arg(argv);

    if (f_r > 0)
        for (; tab[i]; i += 1) {
            if (test_exist(tab[i], flag_l) == 1)
                my_ls_r(tab[i], flag_l, flag_t);
        }
    else if (flag_l == ON)
        for (int j = 0; tab[j]; j += 1) {
            if (test_exist(tab[j], ON) == 1) {
                total(tab[j]);
                list = file_list(tab[j], &size);
                my_ls_l(list, flag_t, size);
            }
        }
    else
        launch_t_ls(argv, flag_t, tab);
}

int launch_t_ls(char **argv, FLAG flag_t, char **tab)
{
    int size = 0;
    int i = 0;
    t_file *list = NULL;

    if (flag_t == ON) {
        for (; tab[i]; i += 1) {
            list = file_list(tab[i], &size);
            my_ls_t(list, ON, size);
        }
    } else {
        for (; tab[i]; i += 1) {
            if (test_exist(tab[i], ON) == 1) {
                list = file_list(tab[i], &size);
                my_ls(list, size);
            }
        }
    }
    return (0);
}

void error_ls(char **argv)
{
    DIR *dir;
    for (int i = 1; argv[i]; i += 1) {
        if (argv[i][0] != '-') {
            dir = opendir(argv[i]);
            if (ENOTDIR != errno && dir == NULL) {
                perror("Error");
                exit (84);
            }
            closedir (dir);
        }
    }
}