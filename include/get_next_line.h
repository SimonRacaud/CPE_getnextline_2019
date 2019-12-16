/*
** EPITECH PROJECT, 2019
** CPE_get_next_line_2019
** File description:
** get next line - header
*/

#ifndef H_GET_NEXT_LINE
#define H_GET_NEXT_LINE

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define READ_SIZE 10

#define MEXIT_ERROR -1

char *get_next_line(int fd);

#endif
