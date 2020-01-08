/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** my_strcat
*/

#include <stdlib.h>
#include "../../include/my_printf.h"
#include "../../include/my_ls.h"

char *my_strcat (char *dest , char const *src)
{
    int len = my_strlen(dest) + my_strlen(src) + 1;
    int i = 0;
    int j = 0;
    int k = 0;
    char *str = malloc(sizeof(char) * len);

    while (j < len) {
        if (j < my_strlen(dest)){
            str[j] = dest[i];
            i++;
        } else {
            str[j] = src[k];
            k++;
        }
        j++;
    }
    return (str);
}

char *give_test(char *filepath, char *next, char *test)
{
    if (filepath[my_strlen(filepath) - 1] == '/')
        test = my_strcat(filepath, next);
    else {
        test = my_strcat(filepath, "/");
        test = my_strcat(test, next);
    }
    return (test);
}

void ls_r_allon(char *filepath)
{
    DIR *dir = opendir(filepath);
    struct dirent *all = readdir(dir);
    int ok = 0;
    struct stat stat1;
    char *test = NULL;

    my_printf("%s :\n", filepath);
    flag_ls_l(filepath, 0);
    for (; all; all = readdir(dir)) {
        test = give_test(filepath, all->d_name, test);
        lstat(test, &stat1);
        if (all->d_name[0] != '.') {
            if (S_ISDIR(stat1.st_mode)) {
                ls_r_allon(test);
                my_printf("\n");
            }
        }
    }
    closedir(dir);
}