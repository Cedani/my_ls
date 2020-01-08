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

void my_ls(t_file *list, int size_list)
{
    for (int i = 0; i < size_list; i += 1)
        my_printf("%s ", parse(list[i].name));
    my_printf("\n");
}

void total(char *filepath)
{
    DIR *dir = opendir(filepath);
    struct dirent *all = readdir(dir);
    struct stat stat1;
    int total = 0;
    char *test = NULL;

    for (; all; all = readdir(dir)) {
        if (all->d_name[0] != '.') {
            test = give_test(filepath, all->d_name, test);
            lstat(test, &stat1);
            total += stat1.st_blocks;
        }
    }
    my_printf("total %d\n", total / 2);
    closedir(dir);
}