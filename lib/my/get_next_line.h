/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get_next_line
*/

#ifndef GET_NEXT_LINE_H_
#define GET_NEXT_LINE_H_

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#define CHECK if (final_buffer == NULL)
#define RETURN_NULL return (NULL);
#define VERIF_MALLOC CHECK RETURN_NULL

#define FREE free(final_buffer);
#define RETURN_NULL return (NULL);
#define EXIT_PROG FREE RETURN_NULL

char *get_next_line(int);

#endif /* !GET_NEXT_LINE_H_ */

#ifndef READ_SIZE
#define READ_SIZE (4096)
#endif /* !READ_SIZE */