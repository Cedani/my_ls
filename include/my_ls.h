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
#include <stddef.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <errno.h>
#include <stdarg.h>

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
void my_ls(t_file *list, int size_list);
char *parse(char *filepath);
char *my_strcat (char *dest , char const *src);
char *give_test(char *filepath, char *next, char *test);
t_file *file_list(char *filepath, int *i);
void my_ls_l(t_file *list, FLAG flag_t, int size_list);
void my_ls_t(t_file *list, FLAG only, int size_list);
void my_ls_r(char *filepath, FLAG flag_l, FLAG flag_t);
void sorting(t_file *list, int size);
int file_len(char *filepath);
void total(char *filepath);
void print_filepath(char *filepath);
int parsing_argument(int argc, char **argv);
void parsing_flag(int argc, char **argv);
int launch_functions(char **argv, FLAG flag_l, FLAG flag_t, int f_r);
int launch_t_ls(char **argv, FLAG flag_t);
void error_ls(char **argv);
char **files_arg(char **argv);
int test_file(char *filepath);
#endif /* !ls */
