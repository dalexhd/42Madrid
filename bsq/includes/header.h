#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>


# define BUFF_SIZE 40960

typedef struct  g_elem
{
    int     size;
    int     size_y;
    char    free;
    char    obs;
    char    square;
}               tree_elemt;

void    ft_putnbr(int nbr);
void    ft_putstr(char *str);
void    ft_putchar(char c);
int     ft_strlen(char *str);
int     **ft_init(char *file, tree_elemt *elem);
int     ft_skip(char *str);
tree_elemt  *ft_init_elem(char *full_buff, tree_elemt *elem);
char    *ft_strcat(char *dest, char *src);
int     **ft_solve(int **map, tree_elemt *elem, int *max);
int     ft_set_number(int **map, int x, int y, int *max);
char    **ft_set(int **map, tree_elemt *elem, int *max);
char    **ft_set_square(char **result, int x, int y, int num, tree_elemt *elem);
void    ft_print(char **map, int size, int y);
void    ft_putstrb(char *str, int len);
# endif
