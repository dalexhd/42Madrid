/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:16:37 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/25 11:57:04 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static	void		floor_ceiling_rows(t_game *game, t_direction step,
	t_direction floor, double dist)
{
	t_ivector		cell;
	t_ivector		fl;
	t_ivector		ce;
	int				x;
	int				cl;

	x = -1;
	while (++x < game->width)
	{
		cell = (t_ivector){.x = (int)(floor.x), .y = (int)(floor.y)};
		fl = (t_ivector){.x = (int)(game->textures.floor.width *
			(floor.x - cell.x)) & (game->textures.floor.width - 1),
		.y = (int)(game->textures.floor.height * (floor.y - cell.y)) &
			(game->textures.floor.height - 1)};
		ce = (t_ivector){.x = (int)(game->textures.ceiling.width *
			(floor.x - cell.x)) & (game->textures.ceiling.width - 1),
		.y = (int)(game->textures.ceiling.height * (floor.y - cell.y)) &
			(game->textures.ceiling.height - 1)};
		floor = (t_direction){.x = floor.x + step.x, .y = floor.y + step.y};
		cl = game->textures.floor.ptr[game->textures.floor.width * fl.y + fl.x];
		set_pixel(game, game->width * game->tmp.y + x, ft_color(cl, dist));
		set_pixel(game, game->width * (game->height - game->tmp.y - 1) + x,
		ft_color(game->textures.ceiling.ptr[game->textures.ceiling.width *
			ce.y + ce.x], dist));
	}
}

static	void		floor_ceiling_cols(t_game *game)
{
	t_vdirection	r_d;
	t_direction		step;
	t_direction		floor;
	double			row_dist;

	game->tmp.y = -1;
	while (++game->tmp.y < game->height)
	{
		r_d = (t_vdirection){.x0 = game->dir.x - game->plane.x,
		.y0 = game->dir.y - game->plane.y, .x1 = game->dir.x + game->plane.x,
		.y1 = game->dir.y + game->plane.y};
		row_dist = (0.5 * game->height) / (game->tmp.y - game->height / 2);
		step = (t_direction){.x = row_dist * (r_d.x1 - r_d.x0) / game->width,
		.y = row_dist * (r_d.y1 - r_d.y0) / game->width};
		floor = (t_direction){.x = game->player.x + row_dist * r_d.x0,
			.y = game->player.y + row_dist * r_d.y0};
		floor_ceiling_rows(game, step, floor, row_dist);
	}
}

void				raycasting(t_game *game)
{
	t_ray			ray;

	game->x = -1;
	floor_ceiling_cols(game);
	while (++game->x < game->width)
	{
		ray = cast_texture(game, cast_ray(game, game->x));
		draw_textured_line(game, ray.start, ray.end, ray);
	}
	draw_sprites(game);
	if (game->bmp)
	{
		take_screenshot(game);
		clear_memory(game);
		exit(EXIT_SUCCESS);
	}
	mlx_put_image_to_window(game->mlx, game->win, game->img.img_ptr, 0, 0);
	fps_counter(game);
}
