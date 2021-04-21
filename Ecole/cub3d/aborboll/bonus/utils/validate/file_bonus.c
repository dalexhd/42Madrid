/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:49:10 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/24 13:08:28 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d_bonus.h"

t_bool		valid_cubfile(char *file)
{
	if (!ft_strendswith(file, ".cub"))
	{
		ft_error("ARGV ERROR: Use: ./CUB3D [file].cub"C_X, false);
		return (false);
	}
	return (true);
}
