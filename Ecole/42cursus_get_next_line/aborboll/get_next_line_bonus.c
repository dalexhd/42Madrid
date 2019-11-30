/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:50:38 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/30 23:11:37 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int i;

	i = 0;
	while (src[i++] != '\0')
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

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

int		ft_new_line(char **cache, char **line, int fd)
{
	int		len;

	len = 0;
	while (cache[fd][len] != '\n' && cache[fd][len] != '\0')
		len++;
	if (cache[fd][len] == '\n')
	{
		*line = ft_substr(cache[fd], 0, len);
		cache[fd] = ft_strdup(cache[fd] + len + 1);
		if (cache[fd][0] == '\0')
		{
			free(cache[fd]);
			cache[fd] = NULL;
		}
	}
	else
	{
		*line = ft_strdup(cache[fd]);
		free(cache[fd]);
		cache[fd] = NULL;
		return (0);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static	char	*cache[255];
	char			buff[BUFFER_SIZE + 1];
	char			*tmp;
	int				ret;

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
	return (ft_return(cache, line, fd, ret));
}
