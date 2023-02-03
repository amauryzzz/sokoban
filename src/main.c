/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/
#include "../include/my.h"

void check_win_con(map_t *map)
{
    map->win_con = 0;
    for (int i = 0; i < map->map_length; i++) {
        for (int j = 0; map->map_array[i][j] != '\0'; j++) {
            switch (map->map_array[i][j]) {
                case 'O':
                    map->win_con++;
                    break;
            }
        }
    }
}

void get_p(map_t *map)
{
    for (int i = 0; map->map_array[i] != NULL; i++) {
        for (int j = 0; map->map_array[i][j] != '\0'; j++) {
            switch (map->map_array[i][j]) {
                case 'P':
                    map->player_x = i;
                    map->player_y = j;
                    break;
            }
        }
    }
}

void move_player_sub(map_t *map)
{
    for (int i = 0; map->map_array[i] != NULL; i++) {
        for (int j = 0; map->map_array[i][j] != '\0'; j++) {
            switch (map->map_array[i][j]) {
                case 'P':
                    map->player_x = i;
                    map->player_y = j;
                    break;
            }
        }
    }
}

int main (int ac, char** av)
{
    struct stat statbuf;
    map_t map;
    map.map_str = av[2];
    if (ac != 2) {
        return (84);
    }
    if (stat(av[1], &statbuf) == -1)
        return 84;
    map = open_map(av[1]);
    check_map_characters(av[1]);
    get_length(&map);
    map.map_width = (my_strlen(map.map_str) / map.map_length) - 1;
    map.map_array = my_str_to_word_array(&map);
    map.map_array_save = my_str_to_word_array(&map);
    display_map(&map);
    return (0);
}
