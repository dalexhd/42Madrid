/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:16:37 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 10:30:50 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	void	floor_ceiling(t_game *game)
{
	int			y;
	int			x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			set_pixel(game, game->width * y + x,
				convert_color(game->colors.floor));
			set_pixel(game, game->width * (game->height - y - 1) + x,
				convert_color(game->colors.ceiling));
			x++;
		}
		y++;
	}
}

void			raycasting(t_game *game)
{
	t_ray		ray;

	game->x = -1;
	floor_ceiling(game);
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
}
