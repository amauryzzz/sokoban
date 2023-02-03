/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/
#include "../include/my.h"

map_t open_map(char *file_path)
{
    map_t map;
    int fd = open(file_path, O_RDONLY);
    int size = size_file(file_path);
    char* map_str;

    if (fd == -1 || size == -1) {
        map.error = 84;
        return (map);
    }
    map_str = malloc((size + 1) * sizeof(char));
    if (!map_str || read(fd, map_str, size) == -1) {
        map.error = 84;
        return (map);
    }
    map_str[size] = '\0';
    map.map_str = map_str;
    return map;
}

int check_map_characters(char *map)
{
    for (int i = 0; i < my_strlen(map); i++) {
        if (map[i] != ' ' && map[i] != '\n' && map[i] != '#' &&
        map[i] != 'X' && map[i] != 'O' && map[i] != 'P') {
            return 84;
        }
    }
    return 0;
}

size_t strlen_line(const char *line)
{
    size_t i = 0;

    for (; line[i] != '\n' && line[i] != '\0'; ++i);
    return i;
}

char** my_str_to_word_array(map_t *map)
{
    int x = 0;
    char** map_array = malloc(sizeof(char *) * (map->map_length + 1));

    for (int i = 0; i <= map->map_length; i ++) {
        map->map_width = strlen_line(&map->map_str[x]);
        map_array[i] = malloc(sizeof(char) * (map->map_width + 1));
        for (int j = 0; j < map->map_width; j++) {
            map_array[i][j] = map->map_str[x];
            x++;
        }
        ++x;
        map_array[i][map->map_width] = '\0';
    }
    map_array[map->map_length + 1] = NULL;
    return map_array;
}

int display_map(map_t *map)
{
    initscr();
    char input = 0;
    while (input != 'a') {
        move_player(&*map, input);
        check_win_con(map);
        if (map->win_con == 0) {
            endwin();
            return (0);
        }
        clear();
        keypad(stdscr, TRUE);
        for (int i = 0; i <= map->map_length; i++)
            printw("%s\n", map->map_array[i]);
        refresh();
        input = getchar();
    }
    endwin();
    return (0);
}
