/*
** EPITECH PROJECT, 2020
** handles possible errors
** File description:
** error handling
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../include/my.h"

int error_handling(char **map, map_t *x)
{
    int y = 1;
    int b = 0;

    while (map[y] != NULL) {
        while (map[y][b] != '\0') {
            if (map[y][b] != '.' && map[y][b] != 'o' && map[y][b] != '\0')
                exit(84);
            b++;
        }
        if (b != x->width)
            exit(84);
        b = 0;
        y++;
    }
    if (y != x->height + 1)
        exit(84);
    return (0);
}
