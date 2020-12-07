/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:59:50 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/25 18:10:29 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

static	void	close_music(void)
{
	FILE		*fp;
	char		path[1035];
	int			pid;

	fp = popen(MUSIC_1""MUSIC_2, "r");
	if (fp == NULL)
		ft_error("Failed to close music!\n", false);
	while (fgets(path, sizeof(path), fp) != NULL)
	{
		pid = ft_atoi(path);
		kill(pid, SIGKILL);
	}
	pclose(fp);
}

int				close_window(t_game *game)
{
	close_music();
	clear_memory(game);
	exit(EXIT_SUCCESS);
}

void			init_window(t_game *game)
{
	if (!game->bmp)
		game->win = mlx_new_window(game->mlx, game->width, game->height, TITLE);
	game->img.img_ptr = mlx_new_image(game->mlx, game->width, game->height);
	game->img.data = (int *)mlx_get_data_addr(game->img.img_ptr,
	&game->img.bpp, &game->img.size_l, &game->img.endian);
}
