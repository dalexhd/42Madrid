/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:48:19 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/24 13:08:28 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

t_bool			is_side(t_ray ray)
{
	return (ray.wall_direction != WEST && ray.wall_direction != EAST);
}

int				ray_direction(t_ray ray)
{
	if (ray.side.x > ray.side.y)
		return (ray.dir.y < 0 ? NORTH : SOUTH);
	return (ray.dir.x < 0 ? WEST : EAST);
}

t_texture		ray_texture(t_game *game, t_ray ray)
{
	t_texture	texture;

	if (ray.wall_direction == NORTH)
		texture = game->textures.north;
	if (ray.wall_direction == SOUTH)
		texture = game->textures.south;
	if (ray.wall_direction == WEST)
		texture = game->textures.west;
	if (ray.wall_direction == EAST)
		texture = game->textures.east;
	return (texture);
}

t_ray			setup_ray(t_game *game, int x)
{
	t_ray		ray;
	double		camera_x;

	camera_x = 2 * x / (double)game->width - 1;
	ray.dir = (t_direction){.x = game->dir.x + game->plane.x * camera_x,
		.y = game->dir.y + game->plane.y * camera_x};
	ray.delta = (t_direction){.x = fabs(1 / ray.dir.x),
		.y = fabs(1 / ray.dir.y)};
	ray.step = (t_ivector){.x = ray.dir.x < 0 ? -1 : 1,
		.y = ray.dir.y < 0 ? -1 : 1};
	ray.map = (t_ivector){.x = (int)game->player.x, .y = (int)game->player.y};
	ray.side = (t_direction){.x = ray.dir.x < 0 ?
		(game->player.x - ray.map.x) * ray.delta.x :
		(ray.map.x + 1.0 - game->player.x) * ray.delta.x,
		.y = ray.dir.y < 0 ? (game->player.y - ray.map.y) * ray.delta.y :
		(ray.map.y + 1.0 - game->player.y) * ray.delta.y
	};
	return (ray);
}
