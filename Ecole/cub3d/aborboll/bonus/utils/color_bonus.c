/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 13:27:57 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/24 13:35:27 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int		rgb_to_hex(int r, int g, int b)
{
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

int		convert_color(t_color color)
{
	return (rgb_to_hex(color.r, color.g, color.b));
}

int		ft_color(int color, double dist)
{
	if (!SHADES || dist <= 1.)
		return (color);
	return (((int)(((0xFF0000 & color) >> 16) / dist) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / dist) << 8)
		+ ((int)((0x0000FF & color) / dist)));
}
