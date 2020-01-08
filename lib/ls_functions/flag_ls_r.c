/*
** EPITECH PROJECT, 2020
** flag_ls_r
** File description:
** flaf R
*/

#include "../../include/my_ls.h"
#include "../../include/my_printf.h"

void flag_ls_r(char *filepath, int flag_l, int flag_t)
{
    DIR *dir = opendir(filepath);
    struct dirent *all = readdir(dir);
    struct stat stat1;
    char *test = NULL;
    int ok = 0;

    if (flag_l == ON) {
        ls_r_allon(filepath);
    }
    else if (flag_t == ON) {
        flag_r_t(filepath);
    } else
        flag_r_normal(filepath);
    closedir(dir);
}

void flag_r_t(char *filepath)
{
    char *test;
    struct stat stat1;
    int i = 0;
    t_file *list = flag_ls_t(filepath, &i);
    int ok = 0;

    for (int j = 0; j < i; j += 1) {
        test = my_strcat(filepath, "/");
        test = my_strcat(test, list[i].name);
        lstat(test, &stat1);
        if (ok == 0) {
            print_flag_t(list, i);
            ok += 1;
        }
        if (S_ISDIR(stat1.st_mode))
            return (flag_r_t(filepath));
    }
}

void print_flag_t(t_file *list, int i)
{
    for (int j = 0; j < i; j += 1) {
        write(1, list[j].name, my_strlen(list[j].name));
        write(1, "\n", 1);
    }
}

void flag_r_normal(char *filepath)
{
    DIR *dir = opendir(filepath);
    struct dirent *all = readdir(dir);
    char *test;
    struct stat stat1;
    int ok = 0;

    for (; all; all = readdir(dir)) {
        lstat(all->d_name, &stat1);
        if (ok == 0) {
            my_ls(filepath);
            ok += 1;
        }
        if (S_ISDIR(stat1.st_mode)) {
            if (filepath[my_strlen(filepath) - 1] == '/')
                test = my_strcat(filepath, all->d_name);
            else {
                test = my_strcat(filepath, "/");
                test = my_strcat(test, all->d_name);
            }
            printf("test = %s\n", test);
            // test = my_strcat(test, all->d_name);
            if (all->d_name[0] != '.')
                return(flag_r_normal(test));
        }
    }
    closedir(dir);
}

void flag_ls_l(char *filepath, FLAG flag_t)
{
    DIR *dir = opendir(filepath);
    struct dirent *all = readdir(dir);
    char *test = NULL;
    struct stat stat1;
    t_file *list = NULL;
    int i = 0;

    if (flag_t == ON) {
        list = flag_ls_t(filepath, &i);
        for (int j = 0; j < i; j += 1) {
            test = give_test(filepath, list[j].name, test);
            lstat(test, &stat1);
            info_file(stat1);
            write(1, list[j].name, my_strlen(list[j].name));
            write(1, "\n", 1);
        }
    } else
        flag_l_normal(dir, all, filepath);
    closedir(dir);
}