#include "../includes/header.h"

char    **ft_set_square(char **result, int x, int y, int num, tree_elemt *elem)
{
    int c;
    int i;
    int t_y;

    c = 0;
    t_y = y;
    while (c < num)
    {
        i = 0;
        y = t_y;
        while (i < num)
        {
            result[x][y] = elem[0].square;
            y--;
            i++;
        }
        c++;
        x--;
    }
    return (result);
}

char    **ft_set(int **map, tree_elemt *elem, int *max)
{
    int     x;
    int     y;
    int     set;
    char    **result;

    if (!(result = (char**)malloc(sizeof(char*) * (elem[0].size))))
        return (NULL);
    x = -1;
    while (++x < elem[0].size)
        if (!(result[x] = (char*)malloc(sizeof(char) * (elem[0].size_y + 1))))
            return (NULL);
    x = 0;
    set = 1;
    while (x < elem[0].size)
     {
         y = 0;
         while (y < elem[0].size_y)
         {
             if (map[x][y] == 0)
                 result[x][y] = elem[0].obs;
             else if (map[x][y] == max[0] && set)
             {
                result = ft_set_square(result, x, y, max[0], elem);
                set = 0;
             }
             else
                 result[x][y] = elem[0].free;
             y++;
         }
         result[x][y] = '\0';
         x++;
     }
    return (result);
}
