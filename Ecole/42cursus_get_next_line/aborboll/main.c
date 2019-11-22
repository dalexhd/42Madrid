/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:55:50 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/21 18:46:55 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc, char const *argv[])
{
	int		i;
	int		fd;
	char	*line;

	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
		close(fd);
	}
	return (0);
}
