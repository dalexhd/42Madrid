#include "includes/header.h"

int     main(int argc, char **argv)
{
    int     max[1];
    int     **map;
    tree_elemt  elem[1];
    char    **result;
    
    max[0] = 0;
    if (argc < 3)
    {
        if (argc == 2)
        {
            if(!(map = ft_init(argv[1], elem))) //Si la carga no es correcta
                return (1);
        }
    }
    else
    {
        ft_putstr("Fichero no valido\n");
        return (1);
    }
    map = ft_solve(map, elem, max); //Resolvemos el mapa
    result = ft_set(map, elem, max); //Preparamos la solución
    ft_print(result, elem[0].size, elem[0].size_y); //Imprimimos en pantalla el resultado
    free(result);//Liberammos la memoria
    free(map);//Liberammos la memoria
    return (0);
}
