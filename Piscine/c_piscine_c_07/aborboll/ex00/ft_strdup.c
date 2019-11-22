/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 23:33:23 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/26 13:55:31 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		z;
	char	*dest;

	i = 0;
	while (src[i] != '\0')
		i++;
	dest = (char*)malloc(i + 1);
	z = 0;
	while (src[z] != '\0')
	{
		dest[z] = src[z];
		z++;
	}
	dest[z] = '\0';
	return (dest);
}
