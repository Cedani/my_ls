/*
** EPITECH PROJECT, 2020
** get_time.c
** File description:
** display last modification time
*/

#include "../../include/my_ls.h"
#include "../../include/my_printf.h"

void get_time(struct stat stat1)
{
    char *s = ctime(&stat1.st_mtime);
    int nb_p = 0;

    write(1, " ", 1);
    for (int i = 3; nb_p < 2; i += 1) {
        if (s[i] == ':')
            nb_p += 1;
        if (nb_p < 2)
            write(1, &s[i], 1);
    }
}

// void device(char **argv, int argc)
// {
//     char *test = NULL;

//     for (int i = 1; argv[i]; i += 1) {
//         if (my_strstr)
//     }
// }

// void swap_string(char **argv, int index) {
//     char *
// }