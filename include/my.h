/*
** EPITECH PROJECT, 2022
** BSQ - my.h
** File description:
** my.h
*/
#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <sys/stat.h>
    #include <pwd.h>
    #include <grp.h>
    #include <time.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include "ncurses.h"

typedef struct map_s {
    int error;
    char* map_str;
    char** map_array;
    char** map_array_save;
    int map_length;
    int map_width;
    int player_x;
    int player_y;
    char next_block;
    char old_block;
    int win_con;
    int lose_con;

} map_t;

typedef struct pos_s {
    int x;
    int y;
} pos_t;

map_t open_map(char *file_path);
int check_map_characters(char *map);
char** my_str_to_word_array(map_t *map);
void get_length(map_t *map);
void my_putchar(char c);
int my_strlen(char* str);
int size_file(char const *file_path);
void move_player_up(map_t *map);
void move_player_down(map_t *map);
void move_player_right(map_t *map);
void move_player_left(map_t *map);
void move_player(map_t *map, char input);
int display_map(map_t *map);
int	my_putstr(char *str);
pos_t parse_goals(map_t *map, pos_t *pos);
pos_t get_nb_of_goals(map_t *map, pos_t pos);
void get_p(map_t *map);
void check_win_con(map_t *map);
void move_player_sub(map_t *map);
void sub_move_player_up(map_t *map);
char** clean_spaces_for_uneven_map(map_t *map);
void get_length(map_t *map);
void sub_move_player_down(map_t *map);
void sub_move_player_left(map_t *map);
void sub_move_player_right(map_t *map);

#endif
