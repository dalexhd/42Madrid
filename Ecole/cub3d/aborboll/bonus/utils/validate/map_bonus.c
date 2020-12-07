/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:33 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 09:57:27 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

t_bool				has_map(t_game *game, t_bool check)
{
	t_bool			valid;

	valid = ft_strlen(game->tmp_map) > 0;
	if (check && !valid)
	{
		ft_error(ERR_MAP_MISSING, false);
		game->valid.map = false;
	}
	return (valid);
}

static	t_ivector	position(t_game *game, int x, int y)
{
	t_ivector		pos;

	pos.x = 0;
	pos.y = 0;
	while (game->map[y] != 0)
	{
		x = 0;
		while (game->map[y][x] != '\0')
		{
			if (game->map[y][x] == game->spawn)
			{
				pos.x = x + 0.5;
				pos.y = y + 0.5;
				return (pos);
			}
			x++;
		}
		y++;
	}
	return (pos);
}

static	t_bool		check_vertical_edges(t_game *game, int x, int y)
{
	while (game->map[y][x] != '\0')
	{
		if (game->map[y][x] != ' ' && game->map[y][x] != '1')
		{
			ft_error("Invalid Map edges!", false);
			return (false);
		}
		x++;
	}
	y = 0;
	while (game->map[y])
		y++;
	y = y - 1;
	x = 0;
	while (game->map[y][x] != '\0')
	{
		if (game->map[y][x] != ' ' && game->map[y][x] != '1')
		{
			ft_error("Invalid Map #3", false);
			return (false);
		}
		x++;
	}
	return (true);
}

static	t_bool		check_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1' || game->map[y][x] == 'f')
		return (true);
	if (game->map[y][x] == '2' || game->map[y][x] == '0' ||
		game->map[y][x] == game->spawn)
	{
		game->map[y][x] = 'f';
		return (check_map(game, x, y + 1) && check_map(game, x, y - 1) &&
		check_map(game, x + 1, y) && check_map(game, x - 1, y) &&
		check_map(game, x + 1, y + 1) && check_map(game, x + 1, y - 1) &&
		check_map(game, x - 1, y + 1) && check_map(game, x - 1, y - 1));
	}
	else
	{
		ft_error("Invalid Map #4", false);
		return (false);
	}
}

t_bool				validate_map(t_game *game)
{
	t_ivector		pos;

	game->map = ft_split(game->tmp_map, '\n');
	pos = position(game, 0, 0);
	if (!(check_vertical_edges(game, 0, 0) && check_map(game, pos.x, pos.y)))
	{
		game->valid.map = false;
		return (false);
	}
	ft_split_del(game->map);
	return (true);
}
