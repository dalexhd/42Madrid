/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:28:09 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/25 22:59:10 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/generic.h"

char	**ft_sq(char **result, int pass[1], int num, t_elem *elem)
{
	int	c;
	int	i;
	int	t_y;

	c = -1;
	t_y = pass[1];
	while (++c < num)
	{
		i = -1;
		pass[1] = t_y;
		while (++i < num)
		{
			result[pass[0]][pass[1]] = elem[0].square;
			pass[1]--;
		}
		pass[0]--;
	}
	return (result);
}

char	**alocate_memory(t_elem *elem, int *x)
{
	char	**result;

	result = (char**)malloc(sizeof(char*) * (elem[0].size));
	*x = -1;
	while (++(*x) < elem[0].size)
		result[*x] = (char*)malloc(sizeof(char) * (elem[0].size_y + 1));
	*x = -1;
	return (result);
}

int		love42(int *y)
{
	*y = -1;
	return (1);
}

char	**ft_set(int **map, t_elem *elem, int *max, int set)
{
	int		x;
	int		y;
	int		pass[2];
	char	**result;

	result = alocate_memory(elem, &x);
	while (++x < elem[0].size && love42(&y))
	{
		while (++y < elem[0].size_y)
		{
			if (map[x][y] == 0)
				result[x][y] = elem[0].obs;
			else if (map[x][y] == max[0] && set)
			{
				pass[0] = x;
				pass[1] = y;
				result = ft_sq(result, pass, max[0], elem);
				set = 0;
			}
			else
				result[x][y] = elem[0].free;
		}
		result[x][y] = '\0';
	}
	return (result);
}
