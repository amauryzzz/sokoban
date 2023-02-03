/*
** EPITECH PROJECT, 2022
** sokoban
** File description:
** sokoban
*/
#include "../include/my.h"

void move_player_up(map_t *map)
{
    if (map->map_array_save[map->player_x][map->player_y] == 'O'
    && map->map_array[map->player_x - 1][map->player_y] != '#'
    && map->map_array[map->player_x - 1][map->player_y] != 'X') {
        map->map_array[map->player_x][map->player_y] = 'O';
        map->map_array[map->player_x - 1][map->player_y] = 'P';
    }
    if (map->map_array_save[map->player_x][map->player_y] == 'O'
    && map->map_array[map->player_x - 1][map->player_y] != '#'
    && map->map_array[map->player_x - 1][map->player_y] == 'X'
    && map->map_array[map->player_x - 2][map->player_y] != '#') {
        map->map_array[map->player_x][map->player_y] = 'O';
        map->map_array[map->player_x - 1][map->player_y] = 'P';
        map->map_array[map->player_x - 2][map->player_y] = 'X';
    }
    sub_move_player_up(map);
}

void move_player_down(map_t *map)
{
    if (map->map_array_save[map->player_x][map->player_y] == 'O'
    && map->map_array[map->player_x + 1][map->player_y] != '#'
    && map->map_array[map->player_x + 1][map->player_y] != 'X') {
        map->map_array[map->player_x][map->player_y] = 'O';
        map->map_array[map->player_x + 1][map->player_y] = 'P';
    }
    if (map->map_array_save[map->player_x][map->player_y] == 'O'
    && map->map_array[map->player_x + 1][map->player_y] != '#'
    && map->map_array[map->player_x + 1][map->player_y] == 'X'
    && map->map_array[map->player_x + 2][map->player_y] != '#') {
        map->map_array[map->player_x][map->player_y] = 'O';
        map->map_array[map->player_x + 1][map->player_y] = 'P';
        map->map_array[map->player_x + 2][map->player_y] = 'X';
    }
    sub_move_player_down(map);
}

void move_player_right(map_t *map)
{
    if (map->map_array_save[map->player_x][map->player_y] == 'O'
    && map->map_array[map->player_x][map->player_y + 1] != '#'
    && map->map_array[map->player_x][map->player_y + 1] != 'X') {
        map->map_array[map->player_x][map->player_y] = 'O';
        map->map_array[map->player_x][map->player_y + 1] = 'P';
    }
    if (map->map_array_save[map->player_x][map->player_y] == 'O'
    && map->map_array[map->player_x][map->player_y + 1] != '#'
    && map->map_array[map->player_x][map->player_y + 1] == 'X'
    && map->map_array[map->player_x][map->player_y + 2] != '#') {
        map->map_array[map->player_x][map->player_y] = 'O';
        map->map_array[map->player_x][map->player_y + 1] = 'P';
        map->map_array[map->player_x][map->player_y + 2] = 'X';
    }
    sub_move_player_right(map);
}

void move_player_left(map_t *map)
{
    if (map->map_array_save[map->player_x][map->player_y] == 'O'
    && map->map_array[map->player_x][map->player_y - 1] != '#'
    && map->map_array[map->player_x][map->player_y - 1] != 'X') {
        map->map_array[map->player_x][map->player_y] = 'O';
        map->map_array[map->player_x][map->player_y - 1] = 'P';
    }
    if (map->map_array_save[map->player_x][map->player_y] == 'O'
    && map->map_array[map->player_x][map->player_y - 1] != '#'
    && map->map_array[map->player_x][map->player_y - 1] == 'X'
    && map->map_array[map->player_x][map->player_y - 2] != '#') {
        map->map_array[map->player_x][map->player_y] = 'O';
        map->map_array[map->player_x][map->player_y - 1] = 'P';
        map->map_array[map->player_x][map->player_y - 2] = 'X';
    }
    sub_move_player_left(map);
}

void move_player(map_t *map, char input)
{
    move_player_sub(map);
    switch (input) {
        case 'A':
            move_player_up(map);
            break;
        case 'B':
            move_player_down(map);
            break;
        case 'C':
            move_player_right(map);
            break;
        case 'D':
            move_player_left(map);
            break;
    }
}
