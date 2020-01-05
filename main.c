/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "include/my_ls.h"

int main(int argc, char **argv)
{
    if (argc == 1)
        my_ls("./");
    else
        my_ls(argv[1]);
    return (0);
}