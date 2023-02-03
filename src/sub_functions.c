/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/
#include "../include/my.h"

void sub_move_player_up(map_t *map)
{
    if (map->map_array[map->player_x - 1][map->player_y] == ' ' ||
        map->map_array[map->player_x - 1][map->player_y] == 'O') {
        map->map_array[map->player_x][map->player_y] = ' ';
        map->map_array[map->player_x - 1][map->player_y] = 'P';
    }
    if (map->map_array[map->player_x - 1][map->player_y] == '#') {
        map->map_array[map->player_x][map->player_y] = 'P';
    }
    if (map->map_array[map->player_x - 1][map->player_y] == 'X' &&
        map->map_array[map->player_x - 2][map->player_y] != '#' &&
        map->map_array[map->player_x - 2][map->player_y] != 'X') {
        map->map_array[map->player_x - 1][map->player_y] = 'P';
        map->map_array[map->player_x - 2][map->player_y] = 'X';
        map->map_array[map->player_x][map->player_y] = ' ';
    }
    if (map->map_array[map->player_x - 1][map->player_y] == 'X' &&
        map->map_array[map->player_x - 2][map->player_y] == '#') {
        map->map_array[map->player_x][map->player_y] = 'P';
    }
}

void sub_move_player_down(map_t *map)
{
    if (map->map_array[map->player_x + 1][map->player_y] == ' ' ||
        map->map_array[map->player_x + 1][map->player_y] == 'O') {
        map->map_array[map->player_x][map->player_y] = ' ';
        map->map_array[map->player_x + 1][map->player_y] = 'P';
    }
    if (map->map_array[map->player_x + 1][map->player_y] == '#') {
        map->map_array[map->player_x][map->player_y] = 'P';
        map->map_array[map->player_x + 1][map->player_y] = '#';
    }
    if (map->map_array[map->player_x + 1][map->player_y] == 'X' &&
        map->map_array[map->player_x + 2][map->player_y] != '#' &&
        map->map_array[map->player_x + 2][map->player_y] != 'X'){
        map->map_array[map->player_x + 1][map->player_y] = 'P';
        map->map_array[map->player_x + 2][map->player_y] = 'X';
        map->map_array[map->player_x][map->player_y] = ' ';
    }
    if (map->map_array[map->player_x + 1][map->player_y] == 'X' &&
        map->map_array[map->player_x + 2][map->player_y] == '#') {
        map->map_array[map->player_x][map->player_y] = 'P';
    }
}

void sub_move_player_right(map_t *map)
{
    if (map->map_array[map->player_x][map->player_y + 1] == ' ' ||
        map->map_array[map->player_x][map->player_y + 1] == 'O') {
        map->map_array[map->player_x][map->player_y] = ' ';
        map->map_array[map->player_x][map->player_y + 1] = 'P';
    }
    if (map->map_array[map->player_x][map->player_y + 1] == '#') {
        map->map_array[map->player_x][map->player_y] = 'P';
        map->map_array[map->player_x][map->player_y + 1] = '#';
    }
    if (map->map_array[map->player_x][map->player_y + 1] == 'X'
        && map->map_array[map->player_x][map->player_y + 2] != '#' &&
        map->map_array[map->player_x][map->player_y + 2] != 'X'){
        map->map_array[map->player_x][map->player_y + 1] = 'P';
        map->map_array[map->player_x][map->player_y + 2] = 'X';
        map->map_array[map->player_x][map->player_y] = ' ';
    }
    if (map->map_array[map->player_x][map->player_y + 1] == 'X' &&
        map->map_array[map->player_y][map->player_y + 2] == '#') {
        map->map_array[map->player_x][map->player_y] = 'P';
    }
}

void sub_move_player_left(map_t *map)
{
    if (map->map_array[map->player_x][map->player_y - 1] == ' ' ||
        map->map_array[map->player_x][map->player_y - 1] == 'O') {
        map->map_array[map->player_x][map->player_y] = ' ';
        map->map_array[map->player_x][map->player_y - 1] = 'P';
    }
    if (map->map_array[map->player_x][map->player_y - 1] == '#') {
        map->map_array[map->player_x][map->player_y] = 'P';
        map->map_array[map->player_x][map->player_y - 1] = '#';
    }
    if (map->map_array[map->player_x][map->player_y - 1] == 'X'
        && map->map_array[map->player_x][map->player_y - 2] != '#' &&
        map->map_array[map->player_x][map->player_y - 2] != 'X') {
        map->map_array[map->player_x][map->player_y - 1] = 'P';
        map->map_array[map->player_x][map->player_y - 2] = 'X';
        map->map_array[map->player_x][map->player_y] = ' ';
    }
    if (map->map_array[map->player_x][map->player_y] == 'X'
        && map->map_array[map->player_x][map->player_y - 2] == '#') {
        map->map_array[map->player_x][map->player_y] = 'P';
    }
}
