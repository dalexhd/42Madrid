/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:14 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 14:54:05 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static	void	parse_screen(t_game *game, char *line)
{
	char		**size;
	char		*resolution;
	t_bool		valid;

	if (!ft_strncmp("R ", line, 2) && (size = ft_split(line, ' ')) &&
		(resolution = ft_strtrim(line, "R ")))
	{
		if (ft_countwords(resolution, ' ') != 2)
			ft_memcpy(size[1], resolution, ft_strlen(resolution));
		mlx_get_screen_size(game->mlx, &game->tmp.width, &game->tmp.height);
		valid = validate_screen(game, resolution, size[1], size[2]);
		ft_strdel(&resolution);
		if (valid == true)
		{
			game->width = ft_atoi(size[1]);
			game->height = ft_atoi(size[2]);
			ft_split_del(size);
		}
		else if (valid == false)
			invalid_screen(game, size);
		else
			ft_split_del(size);
		game->tmp.safe_line = true;
	}
}

static	void	valid_line(t_game *game, char *line)
{
	if (!(!ft_strncmp("R ", line, 2) || !ft_strncmp("NO ", line, 3) ||
		!ft_strncmp("SO ", line, 3) || !ft_strncmp("WE ", line, 3) ||
		!ft_strncmp("WE ", line, 3) || !ft_strncmp("EA ", line, 3) ||
		!ft_strncmp("S ", line, 2) || !ft_strncmp("F ", line, 2) ||
		!ft_strlen(line) || !ft_strncmp("C ", line, 2)) &&
			!has_map(game, false))
	{
		ft_error("Invalid .cub file! Found %s", false, line);
		game->valid.file = false;
	}
}

void			parse_game(t_game *game, char *file)
{
	char		*line;
	char		*trimmed;
	int			fd;

	fd = parse_file(game, file);
	game->mlx = mlx_init();
	game->tmp.nullbef = false;
	while (get_next_line(fd, &line))
	{
		game->tmp.safe_line = false;
		trimmed = ft_strtrim(line, " ");
		parse_screen(game, trimmed);
		parse_textures(game, trimmed);
		parse_map(game, line);
		valid_line(game, line);
		ft_strdel(&trimmed);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	close(fd);
	fill_map(game);
	set_sprites(game);
}
