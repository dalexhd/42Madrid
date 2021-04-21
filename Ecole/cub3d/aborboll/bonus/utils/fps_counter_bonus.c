/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_counter_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 13:55:59 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/25 12:52:55 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void		fps_counter(t_game *game)
{
	char	*fps;
	char	*res;

	game->fps.old_time = game->fps.time;
	game->fps.time = clock();
	game->fps.count = 1.0 / ((game->fps.time - game->fps.old_time) /
		CLOCKS_PER_SEC);
	if (game->fps.showing)
	{
		fps = ft_itoa(round(game->fps.count));
		res = ft_strjoin("FPS: ", fps);
		mlx_string_put(game->mlx, game->win, 10, 20, 0xFFFFFF, res);
		free(fps);
		free(res);
	}
}
