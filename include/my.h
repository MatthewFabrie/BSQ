/*
** EPITECH PROJECT, 2020
** my h header
** File description:
** this file cointains all file prototypes
*/

int my_printf (int n, ...);
void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int convert_to_number(void);
int is_number(void);
int neg_task(void);
int my_array_swap(void);
int check_change(void);
char **my_str_to_word_array(const char *str, const char *separator);

typedef struct square_s
{
    int line;
    int column;
    int x;
    int y;
    int result;
}square_t;

typedef struct values_s
{
    int get_line;
    int get_height;
    int pilar;
    int tray;
    int height;
}values_t;

typedef struct map_s
{
    int height;
    int width;
    int size;
}map_t;

void square(char **map,values_t *square_i, square_t *square_values);
void largest_square(values_t *square_i, square_t *square_values);
void get_length(values_t *square_i, square_t *square_values, char **map);
int map_info(char *filepath);
map_t map_size(char *filepath);
void print_square(values_t *square_i, square_t *square_values, char **map);
int error_handling(char **map, map_t *x);
