/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 17:20:18 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/24 13:07:23 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static	int		texture_file(t_game *game, char *file, char *name)
{
	int			fd;

	if (!ft_strendswith(file, ".xpm") && !ft_strendswith(file, ".png"))
	{
		ft_error("Texture %s must have .xpm or .png format!", false, name);
		free(file);
		game->valid.textures = false;
		return (false);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Error opening \"%s\" texture!", false, file);
		free(file);
		game->valid.textures = false;
		return (false);
	}
	return (fd);
}

static	t_bool	invalid_texture(t_game *game, char *path)
{
	game->valid.textures = false;
	free(path);
	return (false);
}

t_bool			validate_texture(t_game *game, char *path, char *name, char *de)
{
	int			fd;
	t_texture	texture;

	if (de || has_map(game, false))
	{
		ft_error(de ? "Texture "ERR_TEX_LOADED : "Texture "ERR_AFTER_MAP, false,
			de ? name : path);
		return (invalid_texture(game, path));
	}
	if (!(fd = texture_file(game, path, name)))
		return (false);
	close(fd);
	texture = load_texture(game->mlx, path);
	if (!texture.texture)
	{
		ft_error("Invalid \"%s\" texture!", false);
		clear_texture(texture, game->mlx, true);
		clear_memory(game);
		return (invalid_texture(game, path));
	}
	clear_texture(texture, game->mlx, false);
	return (true);
}

t_bool			has_textures(t_game *game)
{
	return (game->textures.north.path &&
	game->textures.south.path &&
	game->textures.west.path &&
	game->textures.east.path &&
	game->textures.sprite.path);
}
