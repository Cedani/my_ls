/*
** EPITECH PROJECT, 2019
** CPool_Day06
** File description:
** my_strstr.c
*/

#include "../../include/my_ls.h"
#include "../../include/my_printf.h"

char *my_strstr(char *str, char const *to_find)
{
    if (str[0] != '\0' &&  to_find[0] == '\0') {
        return str;
    } else {
        if (my_strcmp(str, to_find) == 0) {
            return (1);
        }
        if (my_strcmp(str, to_find) != 0 && str[0] == '\0') {
            return (0);
        } else {
            return (my_strstr(str + 1, to_find));
        }
    }
}