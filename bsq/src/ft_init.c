#include "../includes/header.h"

int     ft_skip(char *str)
{
    int x;

    x = 0;
    while (str[x] != '\n')
        x++;
    return (x + 1);
}

tree_elemt  *ft_init_elem(char *full, tree_elemt *elem)
{
    int x;
    int c;

    x = 0;
    c = 0;
    elem[0].size = 0;
    while (full[x] != '\n')
    {
        while (full[x] >= '0' && full[x] <= '9')
        {
            elem[0].size = elem[0].size * 10 + (full[x] - 48);
            x++;
        }
        elem[0].free = full[x++];
        elem[0].obs = full[x++];
        elem[0].square = full[x++];
    }
    while (full[++x] != '\n')
        c++;
    elem[0].size_y = c;
    return (elem);
}

int     **ft_init(char *file_name, tree_elemt *elem)
{
    int     file;
    int     c;
    int     i;
    int     x;
    int     ret;
    char    buff[40960 + 1];
    char    *full;
    int     **map;

    if((file = open(file_name, O_RDONLY)) == -1)
        file = 0;

    if (!(full = (char*)malloc(sizeof(char) * 1)))
        return (NULL);
    full[0] = '\0';

    while ((ret = read(file, buff, 40960)))
    {
        if (ret == -1)
        {
            write(2, "read() error\n", 13);
            return (NULL);
        }
        buff[ret] = '\0';
        full = ft_strcat(full, buff);
    }
    elem = ft_init_elem(full, elem);
    if (!(map = (int**)malloc(sizeof(int*) * elem[0].size)))
        return (NULL);
    c = 0;
    while (c < elem[0].size)
    {
        if (!(map[c] = (int*)malloc(sizeof(int) * elem[0].size_y)))
            return (NULL);
        c++;
    }
    c = 0;
    x = ft_skip(full);
    while(full[++x])
    {
        i = 0;
        while (full[x] != '\n')
        {
            if (full[x] == elem[0].free)
                map[c][i] = 1;
            if (full[x] == elem[0].obs)
                map[c][i] = 0;
            x++;
            i++;
        }
        c++;
    }
    free(full);
    return (map);
}
