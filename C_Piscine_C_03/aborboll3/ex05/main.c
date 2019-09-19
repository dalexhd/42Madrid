/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:53:19 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/16 17:23:14 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	e;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < size)
	{
		dest[i + j] = src[j];
		j++;
	}
	src[i + j] = '\0';
	e = 0;
	while (src[e] != '\0')
		e++;
	return (e + size);
}

int				main(void)
{
	char			dest[10] = "HolaMundo";
	char			src[6] = "adios";
	unsigned int	size = 10;

	printf("El resultado es: %u\n", ft_strlcat(dest, src, size));
	return (0);
}
