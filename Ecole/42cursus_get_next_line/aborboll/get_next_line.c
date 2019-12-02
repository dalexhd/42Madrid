/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:50:38 by aborboll          #+#    #+#             */
/*   Updated: 2019/12/01 14:01:20 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

int		ft_new_line(char **cache, char **line, int fd, char *buff)
{
	int		len;

	free(buff);
	len = 0;
	while (cache[fd][len] != '\n' && cache[fd][len] != '\0')
		len++;
	if (cache[fd][len] == '\n')
	{
		*line = ft_substr(cache[fd], 0, len);
		cache[fd] = ft_strdup(cache[fd] + len + 1);
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

int		get_next_line(int fd, char **line)
{
	static	char	*cache[255];
	char			*buff;
	char			*tmp;
	int				ret;

	buff = malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (fd < 0 || line == NULL)
		return (-1);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
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
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (cache[fd] == NULL || cache[fd][0] == '\0')
			&& (*line = ft_strdup("")))
		return (0);
	return (ft_new_line(cache, line, fd, buff));
}
