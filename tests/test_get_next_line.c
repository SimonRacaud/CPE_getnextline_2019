/*
** EPITECH PROJECT, 2019
** Unit_Test_Criterion
** File description:
** Test File
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include  <fcntl.h>
#include "get_next_line.h"

static const char *BIG_SENTENCE01 = "Une phrase tres longue, Une phrase tres"\
" longue, Une phrase tres longue, Une phrase tres longue, Une phrase tres lo"\
"ngue, Une phrase tres longue.";

int open_file(char *pathname)
{
    int fd = open(pathname, O_RDONLY);

    return fd;
}

void close_file(int fd)
{
    if (fd != -1)
        close(fd);
}

Test(get_next_line, t01_line_one)
{
    int fd = open_file("tests/test.txt");
    char *str = get_next_line(fd);

    cr_assert_str_eq(str, "Hello world");
    close_file(fd);
}

Test(get_next_line, t02_line_two)
{
    int fd = open_file("tests/test.txt");
    char *str = get_next_line(fd);

    for (int i = 0; i < 1 && str != NULL; i++)
        str = get_next_line(fd);
    cr_assert_str_eq(str, "");
    close_file(fd);
}

Test(get_next_line, t03_line_threes)
{
    int fd = open_file("tests/test.txt");
    char *str = get_next_line(fd);

    for (int i = 0; i < 2 && str != NULL; i++)
        str = get_next_line(fd);
    cr_assert_str_eq(str, "0123456");
    close_file(fd);
}

Test(get_next_line, t04_line_four)
{
    int fd = open_file("tests/test.txt");
    char *str = get_next_line(fd);

    for (int i = 0; i < 3 && str != NULL; i++)
        str = get_next_line(fd);
    cr_assert_str_eq(str, "78");
    close_file(fd);
}

Test(get_next_line, t05_line_five_big_line)
{
    int fd = open_file("tests/test.txt");
    char *str = get_next_line(fd);

    for (int i = 0; i < 4 && str != NULL; i++) {
        str = get_next_line(fd);
    }
    cr_assert_str_eq(str, BIG_SENTENCE01);
    close_file(fd);
}

Test(get_next_line, t06_no_new_line_in_file)
{
    int fd = open_file("tests/test_no_newline.txt");
    char *str = get_next_line(fd);

    cr_assert_str_eq(str, "Hello");
    close_file(fd);
}

Test(get_next_line, t07_unvalid_file)
{
    int fd = 84;
    char *str = get_next_line(fd);

    cr_assert(str == NULL);
}

Test(get_next_line, t08_no_more_line)
{
    int fd = open_file("tests/test_no_newline.txt");
    char *str = get_next_line(fd);

    str = get_next_line(fd);
    cr_assert(str == NULL);
}
