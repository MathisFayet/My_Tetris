/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** my_printf
*/

#ifndef MY_PRINTF_H_
#define MY_PRINTF_H_

const int (*fptr[])(va_list, arg_list_t) = {&disp_percent, &disp_nbr, &disp_nbr,
    &disp_nbr, &disp_char, &disp_str, &disp_binary, &disp_octal, &disp_hexa,
    &disp_hexamaj, &disp_ptr, &disp_nprint, &disp_long};

#endif /* !MY_PRINTF_H_ */