/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 14:18:23 by aborboll          #+#    #+#             */
/*   Updated: 2019/12/06 10:45:35 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_new_line(char **cache, char **line, int fd)
{
	char	*tmp;
	int		len;

	len = 0;
	while (cache[fd][len] != '\n' && cache[fd][len] != '\0')
		len++;
	if (cache[fd][len] == '\n')
	{
		*line = ft_substr(cache[fd], 0, len);
		tmp = ft_strdup(&cache[fd][len + 1]);
		free(cache[fd]);
		cache[fd] = tmp;
		if (cache[fd][0] == '\0')
			ft_strdel(&cache[fd]);
	}
	else
	{
		*line = ft_strdup(cache[fd]);
		ft_strdel(&cache[fd]);
		return (0);
	}
	return (1);
}

static	int	ft_return(char **cache, char **line, int fd, int ret)
{
	if (ret < 0)
		return (-1);
	if (ret == 0 && cache[fd] == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	return (ft_new_line(cache, line, fd));
}

int			ft_get_next_line(int fd, char **line, t_ullong buffer_size)
{
	static	char	*cache[4096];
	char			*buff;
	char			*tmp;
	int				ret;

	if (fd < 0 || line == NULL || buffer_size < 1
		|| !(buff = malloc((sizeof(char) * buffer_size) + 1)))
		return (-1);
	while ((ret = read(fd, buff, buffer_size)) > 0)
	{
		buff[ret] = '\0';
		if (cache[fd] == NULL)
			cache[fd] = ft_strnew(1);
		tmp = ft_strjoin(cache[fd], buff);
		free(cache[fd]);
		cache[fd] = tmp;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (ft_return(cache, line, fd, ret));
}
