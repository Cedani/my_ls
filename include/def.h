/*
** EPITECH PROJECT, 2020
** def.h
** File description:
** define of certain type and function
*/

#ifndef DEF
#define DEF
#include <stdarg.h>

typedef struct func_list_s {
    char c;
    void (*fun)(va_list);
} func_list_t;

#endif /* !DEF */
