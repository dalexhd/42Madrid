/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 15:44:21 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/28 10:51:20 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

static	void		int_char(t_uchar *src, int nb)
{
	src[0] = (t_uchar)(nb);
	src[1] = (t_uchar)(nb >> 8);
	src[2] = (t_uchar)(nb >> 16);
	src[3] = (t_uchar)(nb >> 24);
}

static	void		bmp_header(t_game *game, int fd, t_uchar *bmp)
{
	int				size;

	size = game->width * game->height + 54;
	bmp[0] = (t_uchar)'B';
	bmp[1] = (t_uchar)'M';
	int_char(bmp + 2, size);
	bmp[10] = (t_uchar)54;
	bmp[14] = (t_uchar)40;
	int_char(bmp + 18, game->width);
	int_char(bmp + 22, game->height);
	bmp[26] = (t_uchar)1;
	bmp[28] = (t_uchar)24;
	write(fd, bmp, 54);
}

static void			bmp_pixels(t_game *game, int fd)
{
	int				y;
	int				x;
	int				color;

	y = -1;
	while (++y < game->height)
	{
		x = -1;
		while (++x < game->width)
		{
			color = game->img.data[game->width * (game->height - 1 - y) + x];
			write(fd, &color, 3);
		}
	}
}

int					take_screenshot(t_game *game)
{
	int				fd;
	static t_uchar	bmp[54];

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0666)) < 0)
		return (0);
	bmp_header(game, fd, bmp);
	bmp_pixels(game, fd);
	close(fd);
	return (1);
}
