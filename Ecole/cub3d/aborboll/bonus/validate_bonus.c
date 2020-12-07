/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:56:44 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 09:58:31 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_bool		valid_cub(t_game *game)
{
	return (game->valid.screen &&
	game->valid.textures &&
	game->valid.map &&
	game->valid.file);
}

t_bool		valid_cub_struct(t_game *game)
{
	return (has_screen(game) &&
	has_textures(game) &&
	game->valid.map);
}
