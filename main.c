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
    // int i = 0;
    // t_file *list = file_list("./", &i);
    // my_ls_r("./", OFF, ON);
    // //my_ls("./", OFF, OFF);
    return (0);
}