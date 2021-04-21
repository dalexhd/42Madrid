/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 15:47:40 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 10:54:29 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

t_texture		load_texture(void *mlx_ptr, char *path)
{
	t_texture	texture;

	texture.path = path;
	if (ft_strendswith(path, ".xpm"))
	{
		texture.ext = "xpm";
		texture.texture = mlx_xpm_file_to_image(mlx_ptr, path,
		&texture.width, &texture.height);
	}
	else if (ft_strendswith(path, ".png"))
	{
		texture.ext = "xpm";
		texture.texture = mlx_xpm_file_to_image(mlx_ptr, path,
		&texture.width, &texture.height);
	}
	if (texture.texture)
		texture.ptr = (int *)mlx_get_data_addr(texture.texture,
		&texture.bpp, &texture.size_l, &texture.endian);
	return (texture);
}

static	char	*parse_texture(t_game *game, char *name, size_t sp, char *line)
{
	char		*trimmed_path;

	trimmed_path = NULL;
	if (ft_strnstr(line, name, sp) &&
		(trimmed_path = ft_strtrim(line, name)))
	{
		game->tmp.safe_line = true;
		return (trimmed_path);
	}
	return (trimmed_path);
}

void			parse_textures(t_game *game, char *line)
{
	char		*path;

	path = NULL;
	if ((path = parse_texture(game, "NO ", 3, line)) &&
		validate_texture(game, path, "NO", game->textures.north.path))
		game->textures.north = load_texture(game->mlx, path);
	else if ((path = parse_texture(game, "SO ", 3, line)) &&
		validate_texture(game, path, "SO", game->textures.south.path))
		game->textures.south = load_texture(game->mlx, path);
	else if ((path = parse_texture(game, "WE ", 3, line)) &&
		validate_texture(game, path, "WE", game->textures.west.path))
		game->textures.west = load_texture(game->mlx, path);
	else if ((path = parse_texture(game, "EA ", 3, line)) &&
		validate_texture(game, path, "EA", game->textures.east.path))
		game->textures.east = load_texture(game->mlx, path);
	else if ((path = parse_texture(game, "F ", 2, line)) &&
		validate_texture(game, path, "F", game->textures.floor.path))
		game->textures.floor = load_texture(game->mlx, path);
	else if ((path = parse_texture(game, "C ", 2, line)) &&
		validate_texture(game, path, "F", game->textures.ceiling.path))
		game->textures.ceiling = load_texture(game->mlx, path);
	else if ((path = parse_texture(game, "S ", 2, line)) &&
		validate_texture(game, path, "S", game->textures.sprite.path))
		game->textures.sprite = load_texture(game->mlx, path);
}
