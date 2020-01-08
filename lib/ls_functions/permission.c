/*
** EPITECH PROJECT, 2020
** permission.c
** File description:
** gettin permissions for user
*/

#include "../../include/my_ls.h"
#include "../../include/my_printf.h"

void permission(struct stat stat1)
{
    permissions_usr(stat1);
    permissions_grp(stat1);
    permissions_oth(stat1);
}

void permissions_usr(struct stat stat1)
{
    if (stat1.st_mode & S_IRUSR)
        write(1, "r", 1);
    else
        write(1, "-", 1);
    if (stat1.st_mode & S_IWUSR)
        write(1, "w", 1);
    else
        write(1, "-", 1);
    if (stat1.st_mode & S_IXUSR)
        write(1, "x", 1);
    else
        write(1, "-", 1);
}

void permissions_grp(struct stat stat1)
{
    if (stat1.st_mode & S_IRGRP)
        write(1, "r", 1);
    else
        write(1, "-", 1);
    if (stat1.st_mode & S_IWGRP)
        write(1, "w", 1);
    else
        write(1, "-", 1);
    if (stat1.st_mode & S_IXGRP)
        write(1, "x", 1);
    else
        write(1, "-", 1);
}

void permissions_oth(struct stat stat1)
{
    if (stat1.st_mode & S_IROTH)
        write(1, "r", 1);
    else
        write(1, "-", 1);

    if (stat1.st_mode & S_IWOTH)
        write(1, "w", 1);
    else
        write(1, "-", 1);

    if (stat1.st_mode & __S_ISVTX) {
        if (stat1.st_mode & S_IXOTH)
            write(1, "t", 1);
        else
            write(1, "-", 1);
    } else {
        if (stat1.st_mode & S_IXOTH)
            write(1, "x", 1);
        else
            write(1, "-", 1);
    }
}

void get_username(struct stat stat1)
{
    struct passwd *usr = getpwuid(stat1.st_uid);
    struct group *grp = getgrgid(stat1.st_gid);

    write(1, usr->pw_name, my_strlen(usr->pw_name));
    write(1, " ", 1);
    if (grp)
        write(1, grp->gr_name, my_strlen(grp->gr_name));
    else
        write(1, "0", 1);
}