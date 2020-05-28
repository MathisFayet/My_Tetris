/*
** EPITECH PROJECT, 2019
** my
** File description:
** header file contains prototypes
*/

#ifndef MY_LIB_H_
#define MY_LIB_H_

#include <stdarg.h>

/* MY LIB PROTOTYPES */
int my_putchar(char);
int my_strlen(char const *);
int my_putstr(char const *);
int my_getnbr(char const *);
int my_put_nbr(int);
int my_put_nbr_base(int, char const *);
int my_put_nbr_base_long(long, char const *);
int my_put_nbr_base_longlong(long long, char const *);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char **my_str_to_word_array(char const *, char);
char *get_next_line(int);

/* MY_PRINTF PROTOTYPES */
typedef struct arg_list
{
    char attribut;
    int precision;
    int size_precision;
    char modifier;
    char indicator;
} arg_list_t;

int my_printf(const char *, ...);
int disp_percent(va_list, arg_list_t);
int disp_nbr(va_list, arg_list_t);
int disp_char(va_list, arg_list_t);
int disp_str(va_list, arg_list_t);
int disp_binary(va_list, arg_list_t);
int disp_octal(va_list, arg_list_t);
int disp_hexa(va_list, arg_list_t);
int disp_hexamaj(va_list, arg_list_t);
int disp_ptr(va_list, arg_list_t);
int disp_nprint(va_list, arg_list_t);
int disp_long(va_list, arg_list_t);
int disp_longlong(va_list, arg_list_t);

#endif /* MY_LIB_H_ */
