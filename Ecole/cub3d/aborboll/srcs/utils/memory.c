/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 10:57:57 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 10:40:00 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void			clear_texture(t_texture texture, void *mlx_ptr, t_bool delpath)
{
	if (texture.texture)
		mlx_destroy_image(mlx_ptr, texture.texture);
	if (delpath)
		ft_strdel(&texture.path);
}

static	void	clear_textures(t_game *game, void *mlx_ptr)
{
	clear_texture(game->textures.north, mlx_ptr, true);
	clear_texture(game->textures.east, mlx_ptr, true);
	clear_texture(game->textures.south, mlx_ptr, true);
	clear_texture(game->textures.west, mlx_ptr, true);
	clear_texture(game->textures.sprite, mlx_ptr, true);
}

void			clear_memory(t_game *game)
{
	ft_strdel(&game->tmp_map);
	clear_textures(game, game->mlx);
	if (game->img.img_ptr)
		mlx_destroy_image(game->mlx, game->img.img_ptr);
	if (game->win)
	{
		mlx_clear_window(game->mlx, game->win);
		mlx_destroy_window(game->mlx, game->win);
	}
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (game->map != NULL)
		ft_split_del(game->map);
	free(game->zbuffer);
	free(game->sprites.data);
	free(game);
}
