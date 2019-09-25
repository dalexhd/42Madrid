#include "../includes/header.h"

int     ft_set_number(int **map, int x, int y, int *max)
{
    int num;

    if (map[x][y - 1] < map[x - 1][y - 1])
        num =  map[x][y - 1];
    else
        num = map[x - 1][y - 1];
    if (num > map[x - 1][y])
        num = map[x - 1][y];
    num++;
    if (num > max[0])
        max[0] = num;
    else
        max[0] = max[0];
    return (num);
}

int     **ft_solve(int **map, tree_elemt *elem, int *max)
{
    int x;
    int y;

    x = 0;
    while (x < elem[0].size)
    {
        y = 0;
        while (y < elem[0].size_y)
        {
            if (map[x][y] == 0 || x == 0 || y == 0)
                y++;
            else
            {
                map[x][y] = ft_set_number(map, x, y, max);
                y++;
            }
        }
        x++;
    }
    return (map);
}
