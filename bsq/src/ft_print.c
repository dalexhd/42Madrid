#include "../includes/header.h"

void    ft_print(char **map, int size, int y)
{
    int x;

    x = 0;
    while (x < size)
    {
        ft_putstrb(map[x], y);
        ft_putchar('\n');
        x++;
    }
}
