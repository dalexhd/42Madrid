/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 08:52:16 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/26 13:55:06 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		i;
	int		c;

	i = 1;
	c = 0;
	while (++i < size)
		c += ft_strlen(strs[i]) + ft_strlen(sep);
	dest = (char *)malloc(sizeof(char) * c + 1);
	if (size == 0)
	{
		free(dest);
		return (dest);
	}
	i = -1;
	while (++i < size)
		dest = ft_strcat(ft_strcat(dest, strs[i]), sep);
	return (dest);
}
