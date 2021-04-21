/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:45:59 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 10:37:02 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static	int	parse_color(t_game *game, char *color, char *line)
{
	char	*tmp;
	int		result;

	if (game->valid.colors)
	{
		tmp = NULL;
		if ((tmp = ft_strtrim(color, " ")) && validate_color(game, tmp, line))
		{
			result = ft_atoi(tmp);
			free(tmp);
			return (result);
		}
		if (color == NULL)
			validate_color(game, color, line);
		free(tmp);
		game->valid.colors = false;
	}
	return (-1);
}

void		parse_floor(t_game *game, char *line)
{
	char	**colors;
	char	*color;

	if (game->valid.colors && ft_strnstr(line, "F ", 2) &&
		(color = ft_strtrim(line, "F ")) &&
		(colors = ft_split(color, ',')))
	{
		game->tmp.safe_line = true;
		if (has_floor(game))
		{
			ft_error(ERR_FL_DEF, false);
			game->valid.colors = false;
			free(color);
			return (ft_split_del(colors));
		}
		if (ft_countchars(color, ',') != 2)
			ft_memcpy(colors[0], color, ft_strlen(color));
		game->colors.floor = (t_color){.r = parse_color(game,
			game->valid.colors ? colors[0] : color, color),
			.g = parse_color(game, game->valid.colors ? colors[1] : "0", color),
			.b = parse_color(game, game->valid.colors ? colors[2] : "0", color),
		};
		free(color);
		ft_split_del(colors);
	}
}

void		parse_ceiling(t_game *game, char *line)
{
	char	**colors;
	char	*color;

	if (game->valid.colors && ft_strnstr(line, "C ", 2) &&
		(color = ft_strtrim(line, "C ")) &&
		(colors = ft_split(color, ',')))
	{
		game->tmp.safe_line = true;
		if (has_ceiling(game))
		{
			ft_error(ERR_CE_DEF, false);
			game->valid.colors = false;
			free(color);
			return (ft_split_del(colors));
		}
		if (ft_countchars(color, ',') != 2)
			ft_memcpy(colors[0], color, ft_strlen(color));
		game->colors.ceiling = (t_color){.r = parse_color(game,
			game->valid.colors ? colors[0] : color, color),
			.g = parse_color(game, game->valid.colors ? colors[1] : "0", color),
			.b = parse_color(game, game->valid.colors ? colors[2] : "0", color),
		};
		free(color);
		ft_split_del(colors);
	}
}
