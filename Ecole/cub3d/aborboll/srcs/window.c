/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:59:50 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/24 13:07:23 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		close_window(t_game *game)
{
	clear_memory(game);
	exit(EXIT_SUCCESS);
}

void	init_window(t_game *game)
{
	if (!game->bmp)
		game->win = mlx_new_window(game->mlx, game->width, game->height, TITLE);
	game->img.img_ptr = mlx_new_image(game->mlx, game->width, game->height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
	&game->img.bpp, &game->img.size_l, &game->img.endian);
}
