/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int	my_putstr(char *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str++;
    }
    return (1);
}

int my_strlen(char* str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len = len + 1;
    return (len);
}

int size_file(char const *file_path)
{
    int size;
    struct stat statbuf;

    if (stat(file_path, &statbuf) == -1) {
        return (-84);
    }
    size = statbuf.st_size;
    return (size);
}

void get_length(map_t *map)
{
    map->map_length = 0;
    for (int i = 0; map->map_str[i] != '\0'; i++) {
        if (map->map_str[i] == '\n') {
            map->map_length++;
        }
    }
}
