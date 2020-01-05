/*
** EPITECH PROJECT, 2020
** my_ls.h
** File description:
** ls's useful functions
*/

#ifndef ls
#define ls
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

typedef enum {
    SORT,
    UNSORT
} FLAG;

void my_ls(const char *);
void info_file(struct stat);
void permissions_usr(struct stat stat1);
void permissions_grp(struct stat stat1);
void permissions_oth(struct stat stat1);
void permission(struct stat stat1);
void type_file(struct stat stat1);
void get_username(struct stat stat1);
void get_time(struct stat stat1);
#endif /* !ls */
