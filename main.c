/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "include/my_ls.h"

int main(int argc, char **argv)
{
    if (argc != 1)
        error_ls(argv);
    parsing_argument(argc, argv);
    return (0);
}