/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 12:46:18 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 10:39:14 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int				main_loop(t_game *game)
{
	if (is_moving(game))
		ft_move(game);
	if (is_rotating(game))
		ft_rotate(game);
	ft_shift(game);
	raycasting(game);
	return (TRUE);
}

void			set_pixel(t_game *game, size_t pixel, int color)
{
	game->img.data[pixel] = color;
}

void			draw_textured_line(t_game *game, size_t start,
	size_t end, t_ray ray)
{
	t_texture	texture;
	size_t		i;
	int			text_y;
	int			color;

	i = start - 1;
	texture = ray.texture;
	while (++i < end)
	{
		text_y = (int)ray.texture_pos % texture.height;
		ray.texture_pos += ray.texture_step;
		if (text_y <= texture.height)
			color = texture.ptr[texture.height * text_y + ray.texture_x];
		set_pixel(game, game->width * i + game->x, color);
	}
}
