/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:47:56 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/24 13:08:28 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

t_bool	is_moving(t_game *game)
{
	if (game->player.moving.forward ||
	game->player.moving.backward ||
	game->player.moving.right ||
	game->player.moving.left)
		return (TRUE);
	return (FALSE);
}

t_bool	is_rotating(t_game *game)
{
	if (game->player.rotating.left || game->player.rotating.right)
		return (TRUE);
	return (FALSE);
}

t_bool	is_shifting(t_game *game)
{
	if (game->player.shifting)
		return (TRUE);
	return (FALSE);
}

void	set_player_position(t_game *game, size_t x, size_t y)
{
	game->player.x = (double)x + 0.5;
	game->player.y = (double)y + 0.5;
	game->map[y][x] = '0';
	if (game->spawn == 'N')
		game->dir = (t_direction){.x = 0, .y = -1};
	else if (game->spawn == 'S')
		game->dir = (t_direction){.x = 0, .y = 1};
	else if (game->spawn == 'W')
		game->dir = (t_direction){.x = -1, .y = 0};
	else if (game->spawn == 'E')
		game->dir = (t_direction){.x = 1, .y = 0};
	game->plane.x = -1 * game->dir.y;
	game->plane.y = 1 * game->dir.x;
}
