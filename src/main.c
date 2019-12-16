/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main function
*/

#include "my.h"
#include "get_next_line.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    char *file = "test.txt";
    int fd = open(file, O_RDONLY);
    char *s = get_next_line(fd);

    while (s != NULL) {
        printf(": %s\n", s);
        free(s);
        s = get_next_line(fd);
    }
    close(fd);
    /*while (s) {
        my_putchar(':');
        my_putstr(s);
        my_putchar('\n');
        free(s);
        s = get_next_line(0);
    }*/
    return (0);
}
