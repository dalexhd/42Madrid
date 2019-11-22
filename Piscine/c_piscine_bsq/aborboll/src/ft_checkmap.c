/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:11:24 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/25 23:36:01 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/generic.h"

int	c_m(int **map, t_elem *elem)
{
	int	i;
	int	z;

	i = -1;
	while (elem->size && ++i < elem->size)
	{
		z = -1;
		while (elem->size_y && ++z < elem->size_y)
			if (map[i][z] != 0)
				return (1);
	}
	ft_putstr("map error\n");
	return (0);
}
