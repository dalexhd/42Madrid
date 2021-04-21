/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:55:49 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 10:40:50 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_ray			cast_texture(t_game *game, t_ray ray)
{
	double		wall_x;

	if (!is_side(ray))
		wall_x = game->player.y + ray.dist * ray.dir.y;
	else
		wall_x = game->player.x + ray.dist * ray.dir.x;
	wall_x -= floor(wall_x);
	ray.texture_x = wall_x * (double)ray.texture.width;
	ray.texture_step = (double)ray.texture.height / ray.height;
	ray.texture_pos = (ray.start - game->height / 2 + ray.height / 2)
		* ray.texture_step;
	return (ray);
}

static	t_ray	cast_ray2(t_game *game, t_ray ray, int x)
{
	if (!is_side(ray))
		ray.dist = (ray.map.x - game->player.x +
			(1 - ray.step.x) / 2) / ray.dir.x;
	else
		ray.dist = (ray.map.y - game->player.y +
			(1 - ray.step.y) / 2) / ray.dir.y;
	ray.height = (int)(game->height / ray.dist);
	ray.start = -ray.height / 2 + game->height / 2;
	ray.end = ray.height / 2 + game->height / 2;
	if (ray.start < 0)
		ray.start = 0;
	if (ray.end >= game->height)
		ray.end = game->height - 1;
	if (ray.end < 0)
		ray.end = 0;
	game->zbuffer[x] = ray.dist;
	return (ray);
}

t_ray			cast_ray(t_game *game, int x)
{
	t_ray		ray;
	t_bool		hit;

	ray = setup_ray(game, x);
	hit = false;
	while (hit == false)
	{
		ray.wall_direction = ray_direction(ray);
		ray.texture = ray_texture(game, ray);
		if (ray.side.x < ray.side.y)
		{
			ray.side.x += ray.delta.x;
			ray.map.x += ray.step.x;
		}
		else
		{
			ray.side.y += ray.delta.y;
			ray.map.y += ray.step.y;
		}
		if (game->map[ray.map.y][ray.map.x] == '1')
			hit = true;
	}
	return (cast_ray2(game, ray, x));
}
