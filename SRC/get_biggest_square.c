/*
** EPITECH PROJECT, 2020
** get_largest_square
** File description:
** this function will search for the largest square in the map
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../include/my.h"

void square(char **map, values_t *square_i, square_t *square_values)
{
    square_i->tray = 1;

    while (square_i->tray <= square_i->height) {
        while (map[square_i->tray][square_i->pilar] != '\0') {
            while (map[square_i->tray][square_i->pilar + square_i->get_line] \
            != 'o' && map[square_i->tray][square_i->pilar + square_i->get_line]\
             != '\0')
                square_i->get_line++;
            get_length(square_i, square_values, map);
            square_i->pilar++;
            square_i->get_line = 0;
        }
        square_i->tray++;
        square_i->pilar = 0;
    }
    return;
}

void get_length(values_t *square_i, square_t *square_values, char **map)
{
    int get_width = 0;

    square_i->get_height = 1;
    while (square_i->get_height < square_i->get_line && (square_i->tray \
    + square_i->get_height) <= square_i->height && map[square_i->tray +\
     square_i->get_height][square_i->pilar] != 'o') {
        for (;map[square_i->tray + square_i->get_height][square_i->pilar \
        + get_width] != 'o' && map[square_i->tray + square_i->get_height] \
        [square_i->pilar + get_width]; get_width++);
        if (get_width < square_i->get_line && get_width != 0) {
                square_i->get_line = get_width;
        }
        square_i->get_height++;
        get_width = 0;
    }
    largest_square(square_i, square_values);
}

void largest_square(values_t *square_i, square_t *square_values)
{
    if (square_i->get_line > square_values->x && square_i->get_height > \
    square_values->y) {
        square_values->line = square_i->tray;
        square_values->column = square_i->pilar;
        square_values->x = square_i->get_line;
        square_values->y = square_i->get_height;
        if ((square_values->x - square_values->y) > 0) {
            while ((square_values->x - square_values->y) != 0)
                square_values->x--;
        }
        if (square_values->result < square_values->x)
            square_values->result = square_values->x;
    }
    return;
}

void print_square(values_t *square_i, square_t *square_values, char **map)
{
    int x = 0;
    int y = 0;

    while (y < square_values->y) {
        while (x < square_values->x) {
            map[square_values->line + y][square_values->column + x] = 'x';
            x++;
        }
        x = 0;
        y++;
    }
    x = 1;
    while (x < square_i->height + 1) {
        my_putstr(map[x]);
        x++;
    }
}