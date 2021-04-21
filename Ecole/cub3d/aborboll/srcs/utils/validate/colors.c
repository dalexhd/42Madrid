/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:21 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/24 13:07:23 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_bool	has_colors(t_game *game)
{
	return (has_floor(game) && has_ceiling(game));
}

t_bool	has_floor(t_game *game)
{
	return (game->colors.floor.r != -1 &&
	game->colors.floor.g != -1 &&
	game->colors.floor.b != -1);
}

t_bool	has_ceiling(t_game *game)
{
	return (game->colors.ceiling.r != -1 &&
	game->colors.ceiling.g != -1 &&
	game->colors.ceiling.b != -1);
}

t_bool	validate_color(t_game *game, char *color, char *line)
{
	int	num;

	if (has_map(game, false))
	{
		ft_error("Color "ERR_AFTER_MAP, false, line);
		return (false);
	}
	if (color == NULL || ft_strlen(color) < 1)
	{
		ft_error("Invalid colors length!", false);
		return (false);
	}
	else if (!ft_strevery(color, ft_isdigit))
	{
		ft_error("Invalid RGB number. Found %s", false, color);
		return (false);
	}
	else if ((num = ft_atoi(color)) > 255)
	{
		ft_error("Max color value is 255. Found %i", false, num);
		return (false);
	}
	return (true);
}
