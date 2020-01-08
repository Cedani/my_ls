/*
** EPITECH PROJECT, 2020
** flag_ls_r
** File description:
** flaf R
*/

#include "../../include/my_ls.h"
#include "../../include/my_printf.h"

void my_ls_r(char *filepath, FLAG flag_l, FLAG flag_t)
{
    int i = 0;
    t_file *list = file_list(filepath, &i);
    struct stat stat1;

    print_filepath(filepath);
    if (flag_l == ON) {
        total(filepath);
        my_ls_l(list, flag_t, i);
    }
    else if (flag_t == ON)
        my_ls_t(list, ON, i);
    else
        my_ls(list, i);
    my_printf("\n");
    for (int j = 0; j < i; j += 1) {
        lstat(list[j].name, &stat1);
        if (S_ISDIR(stat1.st_mode)) {
            my_ls_r(list[j].name, flag_l, flag_t);
        }
    }
}

void my_ls_t(t_file *list, FLAG only, int size_list)
{
    sorting(list, size_list);

    if (only == ON)
        for (int i = 0; i < size_list; i += 1)
            my_printf("%s ", parse(list[i].name));
    my_printf("\n");
}

char *parse(char *filepath)
{
    int j = 0;
    int i = 0;
    int k = 0;
    char *name = NULL;

    for (; filepath[i]; i += 1)
        if (filepath[i] == '/')
            j = i;
    name = malloc(sizeof(*name) * (my_strlen(filepath) - j));
    if (j == 0 && filepath[j] != '/')
        i = j;
    else
        i = j + 1;
    for (; filepath[i]; i += 1) {
        name[k] = filepath[i];
        k += 1;
    }
    name[k] = '\0';
    return (name);
}

t_file *file_list(char *filepath, int *i)
{
    *i = file_len(filepath);
    DIR *dir = opendir(filepath);
    struct stat stat1;
    struct dirent *all = readdir(dir);
    t_file *list = malloc(sizeof(*list) * *i);
    char *test = NULL;

    for (int j = 0; j < *i; all = readdir(dir)) {
        test = give_test(filepath, all->d_name, test);
        if (all->d_name[0] != '.') {
            lstat(test, &stat1);
            list[j].name = test;
            list[j].time = stat1.st_mtime;
            j += 1;
        }
    }
    return (list);
}