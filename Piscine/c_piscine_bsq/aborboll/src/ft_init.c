/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 09:27:34 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/25 23:35:43 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/generic.h"

int		check_parm(t_elem *elem)
{
	if (!ft_isprint(elem->free)
		|| !ft_isprint(elem->obs)
		|| !ft_isprint(elem->square)
		|| elem->square == elem->obs
		|| elem->square == elem->free
		|| elem->obs == elem->free)
	{
		return (0);
	}
	return (1);
}

t_elem	*ft_init_elem(char *full, t_elem *elem)
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
		if (check_parm(elem) == 0)
			return (0);
	}
	while (full[++x] != '\n')
		c++;
	elem[0].size_y = c;
	return (elem);
}

char	*set(int x, char *full, t_elem *elem, int **map)
{
	int	c;
	int	i;

	c = 0;
	i = 0;
	while (full[x])
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
		x++;
	}
	return (full);
}

int		**ft_init(char *file_name, t_elem *elem, int c, int ret)
{
	int		file;
	char	buffer[BUFF_SIZE + 1];
	char	*full;
	int		**map;

	if ((file = is_open(file_name)) == -1)
		return (0);
	full = (char*)malloc(sizeof(char) * 1);
	full[0] = '\0';
	while ((ret = read(file, buffer, BUFF_SIZE)))
	{
		if (ret == -1)
		{
			return (NULL);
		}
		buffer[ret] = '\0';
		full = ft_strmemcat(full, buffer);
	}
	if ((elem = ft_init_elem(full, elem)) == 0)
		return (0);
	map = (int**)malloc(sizeof(int*) * elem[0].size);
	while (++c < elem[0].size)
		map[c] = (int*)malloc(sizeof(int) * elem[0].size_y);
	free(set(ft_skip(full), full, elem, map));
	return (map);
}
