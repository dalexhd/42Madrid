/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:21:23 by aborboll          #+#    #+#             */
/*   Updated: 2019/12/01 13:08:08 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	if (!(str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, t_uint start, size_t len)
{
	char	*new;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	if (ft_strlen(s) < start)
		return (new);
	s += start;
	while (i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		u;

	if (s1 == '\0' || s2 == '\0')
		return (0);
	if (!(str = (char*)malloc(
		sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = '\0';
	i = ft_strlen(str);
	u = 0;
	while (s2[u] != '\0')
	{
		str[u + i] = s2[u];
		u++;
	}
	str[i + u] = '\0';
	return (str);
}

void	ft_strdel(char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
	return ;
}
