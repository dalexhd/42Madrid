/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:55:50 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/30 22:47:02 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putstr(char *s)
{
	int i;

	if (s != '\0')
	{
		i = 0;
		while (s[i] != '\0')
			write(1, &s[i++], 1);
	}
}

int		main(void)
{
	int		fd;
	char	*line;

	fd = open("tests/test2", O_RDONLY);
	while ((get_next_line(fd, &line)) == 1)
	{
		ft_putstr(line);
		write(1, "\n", 1);
	}
	close(fd);
	return (0);
}
