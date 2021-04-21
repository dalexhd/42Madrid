/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 10:33:47 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/25 15:49:40 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

void	ft_shift(t_game *game)
{
	if (game->player.shifting)
	{
		game->player.speed = ((double)PL_SPEED * 3.6 / 100.0) / 2;
		game->player.rotate_speed = ((double)RT_SPEED * M_PI / 180) / 1.5;
	}
	else
	{
		game->player.speed = (double)PL_SPEED * 3.6 / 100.0;
		game->player.rotate_speed = (double)RT_SPEED * M_PI / 180;
	}
}

int		key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		close_window(game);
	if (keycode == KEY_W)
		game->player.moving.forward = true;
	if (keycode == KEY_S)
		game->player.moving.backward = true;
	if (keycode == KEY_D)
		game->player.moving.right = true;
	if (keycode == KEY_A)
		game->player.moving.left = true;
	if (keycode == KEY_RIGHT)
		game->player.rotating.right = true;
	if (keycode == KEY_LEFT)
		game->player.rotating.left = true;
	if (keycode == KEY_SHIFT)
		game->player.shifting = true;
	if (keycode == KEY_TAB)
		game->fps.showing = true;
	return (0);
}

int		key_release(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->player.moving.forward = false;
	if (keycode == KEY_S)
		game->player.moving.backward = false;
	if (keycode == KEY_D)
		game->player.moving.right = false;
	if (keycode == KEY_A)
		game->player.moving.left = false;
	if (keycode == KEY_RIGHT)
		game->player.rotating.right = false;
	if (keycode == KEY_LEFT)
		game->player.rotating.left = false;
	if (keycode == KEY_SHIFT)
		game->player.shifting = false;
	if (keycode == KEY_TAB)
		game->fps.showing = false;
	return (0);
}

void	load_controls(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, &key_press, game);
	mlx_hook(game->win, 3, 1L << 1, &key_release, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
}
