/*
** EPITECH PROJECT, 2020
** my_bsq
** File description:
** finds the biggest square in a map
*/

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

#include "../include/my.h"

map_t map_size(char *filepath)
{
    map_t map_value;
    int fd = open(filepath, O_RDONLY);
    char *buff = malloc(sizeof(char) * 1000000);
    int height = 0;
    int width = 0;
    int i = 0;

    if (fd == -1)
        exit(84);
    read(fd, buff, 1000000);
    for (; buff[i] >= '0' && buff[i] <= '9'; i++)
        height = height * 10 + (buff[i] - '0');
    i++;
    for (; buff[i++] != '\n'; width++);
    close(fd);
    if (height > 2000)
        exit(84);
    map_value.height = height;
    map_value.width = width;
    map_value.size = width * height + height + 20;
    return (map_value);
}

square_t init_square()
{
    square_t square;

    square.line = 0;
    square.column = 0;
    square.x = 0;
    square.y = 0;
    square.result = 0;
    return (square);
}

int map_info(char *filepath)
{
    map_t x;
    int fd = 0;
    char *buff;
    char **map;
    square_t square_values = init_square();
    values_t square_i = {.get_line = 0, .get_height = 0, .pilar = 0, .tray = 1\
    , .height = 0};

    x = map_size(filepath);
    buff = malloc(sizeof(char) * x.size);
    fd = open(filepath, O_RDONLY);
    read(fd, buff, x.size);
    map = my_str_to_word_array(buff, "\n");
    square_i.height = x.height;
    error_handling(map, &x);
    square(map, &square_i, &square_values);
    print_square(&square_i, &square_values, map);
    free(buff);
    close(fd);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc != 2)
        exit(84);
    
    map_info(argv[1]);
    return (0);
    
}
