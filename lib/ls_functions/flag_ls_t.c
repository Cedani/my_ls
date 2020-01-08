/*
** EPITECH PROJECT, 2020
** flag_ls_t.c
** File description:
** flag ls t
*/

#include "../../include/my_ls.h"
#include "../../include/my_printf.h"

void swap(t_file *list, int fir, int sec)
{
    t_file tmp = list[fir];
    list[fir] = list[sec];
    list[sec] = tmp;
}

void sorting(t_file *list, int size)
{
    int swapped = 0;

    for (int i = 0; i < size - 1; i += 1)
        if (list[i].time < list[i + 1].time) {
            swap(list, i, i + 1);
            swapped = 1;
        }

    if (swapped != 0)
        sorting(list, size);
}

int file_len(char *filepath)
{
    DIR *dir = opendir(filepath);
    struct dirent *all = readdir(dir);
    int i = 0;

    for (; all; all = readdir(dir))
        if (all->d_name[0] != '.')
            i += 1;
    closedir(dir);
    return (i);
}

t_file *flag_ls_t(char *filepath, int *i)
{
    int len = file_len(filepath);
    DIR *dir = opendir(filepath);
    char *test = NULL;
    struct dirent *all = readdir(dir);
    t_file *list = malloc(sizeof(*list) * len);
    struct stat stat1;

    for (; *i < len; all = readdir(dir)) {
        test = give_test(filepath, all->d_name, test);
        if (all->d_name[0] != '.') {
            lstat(test, &stat1);
            list[*i].name = all->d_name;
            list[*i].time = stat1.st_mtime;
            *i += 1;
        }
    }
    sorting(list, *i);
    closedir(dir);
    *i = len;
    return (list);
}

void my_ls (char *filepath)
{
    DIR *dir = opendir(filepath);
    struct dirent *all = readdir(dir);

    for (; all; all = readdir(dir)) {
        if (all->d_name[0] != '.') {
            write(1, all->d_name, my_strlen(all->d_name));
            write(1, "\n", 1);
        }
    }
    closedir(dir);
}