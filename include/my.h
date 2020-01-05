/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** useful functions
*/

#ifndef MY
#define MY
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_printf.h"
#define maj(devnum)           (((unsigned int)devnum & 0xFF00U) >> 8)
#define min(devnum)           ((unsigned int)devnum & 0xFFFF00FFU)

void parse(char *filepath);
int error_ls(char *filepath);
int info_file(char *filepath);
void type_file(struct stat stat1);
void min_maj(struct stat stat1);
#endif /* !MY */
