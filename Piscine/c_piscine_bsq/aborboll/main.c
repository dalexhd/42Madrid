/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:28:29 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/25 23:01:15 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib/generic.h"

void	single(int argc, char **argv)
{
	int		max[1];
	int		**map;
	t_elem	elem[1];
	char	**result;

	max[0] = 1;
	if (!ft_checkerror(argc)
	|| !(map = ft_init(argv[1], elem, -1, -1))
	|| !(c_m(map, elem)))
		return ;
	map = ft_solve(map, elem, max);
	result = ft_set(map, elem, max, 1);
	ft_print(result, elem[0].size, elem[0].size_y);
	free(result);
	free(map);
}

void	multiple(int argc, char **argv)
{
	int		max[1];
	int		**map;
	t_elem	elem[1];
	char	**result;
	int		i;

	i = 0;
	while (i < (argc - 1))
	{
		max[0] = 1;
		if ((map = ft_init(argv[i + 1], elem, -1, 0)) && (c_m(map, elem)) != -1)
		{
			map = ft_solve(map, elem, max);
			result = ft_set(map, elem, max, 1);
			ft_print(result, elem[0].size, elem[0].size_y);
			free(result);
			free(map);
			if (i < (argc - 2))
				ft_putchar('\n');
		}
		else
			ft_putstr("map error\n");
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		single(argc, argv);
	}
	else if (argc > 2)
	{
		multiple(argc, argv);
	}
	else if (argc == 1)
	{
		argv[1] = "map";
		single(argc, argv);
	}
	return (0);
}
