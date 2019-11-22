/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:50:48 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 21:11:23 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include "../lib/generic.h"

int		is_open(char path[])
{
	int	file;

	file = open(path, O_RDONLY);
	return (file);
}

char	*get_dir(char *lang)
{
	static char	path[30];

	strcpy(path, "./dictionaries/");
	strcat(path, lang);
	strcat(path, ".dict");
	return (path);
}

char	*load_dictionary(char *lang)
{
	int				file;
	char			c;
	int				i;
	static char		*content;
	static char		*path;

	path = get_dir(lang);
	file = is_open(path);
	if (file == -1)
		ft_error("Dictionary file could not be found.\n");
	i = 0;
	while (read(file, &c, sizeof(c) != '\0'))
		i++;
	content = malloc(sizeof(char) * i);
	i = 0;
	close(file);
	if (is_open(path) == -1)
		ft_error("Dictionary file could not be found.\n");
	while (read(file, &c, sizeof(c) != '\0'))
		content[i++] = c;
	content[i] = '\0';
	close(file);
	return (content);
}
