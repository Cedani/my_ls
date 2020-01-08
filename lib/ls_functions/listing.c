/*
** EPITECH PROJECT, 2020
** listing;c
** File description:
** listing.c
*/

#include "../../include/my_ls.h"
#include "../../include/my_printf.h"

void info_file(struct stat stat1)
{
    type_file(stat1);
    permission(stat1);
    write(1, " ", 1);
    my_put_nbr(stat1.st_nlink);
    write(1, " ", 1);
    get_username(stat1);
    write(1, "  ", 2);
    my_put_nbr(stat1.st_size);
    get_time(stat1);
    write(1, " ", 1);
}

void type_file(struct stat stat1)
{
    if (S_ISREG(stat1.st_mode))
        write(1, "-", 1);
    if (S_ISDIR(stat1.st_mode))
        write(1, "d", 1);
    if (S_ISLNK(stat1.st_mode))
        write(1, "l", 1);
    if (S_ISCHR(stat1.st_mode))
        write(1, "c", 1);
    if (S_ISBLK(stat1.st_mode))
        write(1, "b", 1);
}

void my_ls_l(t_file *list, FLAG flag_t, int size_list)
{
    struct stat stat1;
    char *test = NULL;

    if (flag_t == ON)
        sorting(list, size_list);
    for (int i = 0; i < size_list; i += 1) {
        lstat(list[i].name, &stat1);
        info_file(stat1);
        test = parse(list[i].name);
        my_printf(" %s\n", test);
    }
    free(test);
}