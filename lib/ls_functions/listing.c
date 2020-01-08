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
}

void flag_l_normal(DIR *dir, struct dirent *all, char *filepath)
{
    char *test;
    struct stat stat1;

    for (int i = 0; all; all = readdir(dir)) {
        if (all->d_name[0] != '.') {
            test = my_strcat(filepath, "/");
            test = my_strcat(test, all->d_name);
            lstat(test, &stat1);
            info_file(stat1);
            write(1, all->d_name, my_strlen(all->d_name));
            write(1, "\n", 1);
        }
    }
}