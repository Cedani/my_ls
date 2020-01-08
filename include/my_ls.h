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
    ON,
    OFF
} FLAG;

typedef struct s_file {
    char *name;
    time_t time;
} t_file;

void info_file(struct stat);
void permissions_usr(struct stat stat1);
void permissions_grp(struct stat stat1);
void permissions_oth(struct stat stat1);
void permission(struct stat stat1);
void type_file(struct stat stat1);
void get_username(struct stat stat1);
void get_time(struct stat stat1);
void my_ls(char *filepath);
t_file *flag_ls_t(char *filepath, int *i);
void flag_ls_r(char *filepath, int flag_l, int flag_t);
void flag_r_t(char *filepath);
void print_flag_t(t_file *list, int i);
void flag_r_normal(char *filepath);
void flag_l_normal(DIR *dir, struct dirent *all, char *filepath);
void ls_r_allon(char *filepath);
void print_flag_t(t_file *list, int i);
void flag_ls_l(char *filepath, FLAG flag_t);
char *my_strcat (char *dest , char const *src);
char *give_test(char *filepath, char *next, char *test);
#endif /* !ls */
