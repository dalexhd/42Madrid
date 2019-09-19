/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:53:19 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/16 13:07:12 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strcat(char *src, char *dest)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	while (dest[j] != '\0')
	{
		src[i + j] = dest[j];
		j++;
	}
	src[i + j] = '\0';
	return (src);
}

int		main(void)
{
	char	src[] = "hola";
	char	dest[] = "holaMUNDO";

	printf("%s\n", ft_strcat(src, dest));
	return (0);
}
