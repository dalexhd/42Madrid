/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/22 10:18:33 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 10:44:20 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	void		order_sprites(t_game *game)
{
	size_t			i;
	size_t			k;
	t_sprite		tmp;

	if (game->sprites.count == 0)
		return ;
	i = -1;
	while (++i < game->sprites.count)
		game->sprites.data[i].d = hypot(game->sprites.data[i].x -
			game->player.x, game->sprites.data[i].y - game->player.y);
	i = -1;
	while (++i < game->sprites.count - 1)
	{
		k = i;
		while (++k < game->sprites.count)
		{
			if (game->sprites.data[i].d < game->sprites.data[k].d)
			{
				tmp = game->sprites.data[i];
				game->sprites.data[i] = game->sprites.data[k];
				game->sprites.data[k] = tmp;
			}
		}
	}
}

static	t_sprite	init_sprite(t_game *game, t_sprite sprite)
{
	sprite.x = sprite.x - game->player.x;
	sprite.y = sprite.y - game->player.y;
	sprite.inv_det = 1.0 / (game->plane.x * game->dir.y - game->dir.x
		* game->plane.y);
	sprite.transform.x = sprite.inv_det * (game->dir.y * sprite.x - game->dir.x
		* sprite.y);
	sprite.transform.y = sprite.inv_det * (-game->plane.y * sprite.x +
		game->plane.x * sprite.y);
	sprite.screen_x = (int)((game->width / 2) *
		(1 + sprite.transform.x / sprite.transform.y));
	sprite.height = abs((int)(game->height / (sprite.transform.y)));
	sprite.start.y = -sprite.height / 2 + game->height / 2;
	if (sprite.start.y < 0)
		sprite.start.y = 0;
	sprite.end.y = sprite.height / 2 + game->height / 2;
	if (sprite.end.y >= game->height)
		sprite.end.y = game->height - 1;
	sprite.width = fabs((int)(game->height / (sprite.transform.y)));
	sprite.start.x = -sprite.width / 2 + sprite.screen_x;
	if (sprite.start.x < 0)
		sprite.start.x = 0;
	sprite.end.x = sprite.width / 2 + sprite.screen_x;
	if (sprite.end.x >= game->width)
		sprite.end.x = game->width - 1;
	return (sprite);
}

static	void		draw_sprite(t_game *game, t_sprite spr)
{
	int				x;
	int				y;
	int				k;
	t_texture		tex;

	x = spr.start.x - 1;
	tex = game->textures.sprite;
	while (++x < spr.end.x)
	{
		spr.texture.x = (x - (-spr.width / 2 + spr.screen_x)) *
			tex.width / spr.width;
		if (spr.transform.y > 0 && x > 0 && x < game->width &&
			spr.transform.y < game->zbuffer[x])
		{
			y = spr.start.y - 1;
			while (++y < spr.end.y)
			{
				k = y * 256 - game->height * 128 + spr.height * 128;
				spr.texture.y = ((k * tex.height) / spr.height) / 256;
				spr.color = tex.ptr[tex.width * spr.texture.y + spr.texture.x];
				if ((spr.color & 0x00ffffff) != 0)
					set_pixel(game, game->width * y + x, spr.color);
			}
		}
	}
}

void				draw_sprites(t_game *game)
{
	size_t			i;

	i = -1;
	order_sprites(game);
	i = -1;
	while (++i < game->sprites.count)
		draw_sprite(game, init_sprite(game, game->sprites.data[i]));
}

void				set_sprites(t_game *game)
{
	size_t			y;
	size_t			x;
	size_t			i;

	if (valid_cub_struct(game))
	{
		if (has_map(game, false))
		{
			game->zbuffer = malloc(sizeof(double) * game->width);
			game->sprites.data = malloc(sizeof(t_sprite) * game->sprites.count);
			y = -1;
			i = -1;
			while (game->map[++y])
			{
				x = -1;
				while (game->map[y][++x])
					if (game->map[y][x] == '2')
						game->sprites.data[++i] = (t_sprite){.y = (double)y +
							0.5, .x = (double)x + 0.5, .d = (double)0};
			}
		}
	}
}
