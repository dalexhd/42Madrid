/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:50:27 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/24 13:08:28 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int		parse_file(t_game *game, char *file)
{
	int	fd;

	if (!valid_cubfile(file))
	{
		clear_memory(game);
		exit(EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		clear_memory(game);
		ft_error(ERR_FILE_OP, true, file);
	}
	return (fd);
}
