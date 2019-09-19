/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:53:19 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/16 13:22:36 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int c;

	i = 0;
	while (str[i] != '\0')
	{
		c = 0;
		while (to_find[c] == str[i + c])
		{
			if (to_find[c + 1] == '\0')
			{
				return (str + i);
			}
			c++;
		}
		i++;
	}
	return (0);
}

int		main(void)
{
	char str[10] = "HolaMundo";
	char to_find[5] = "Mu";

	printf("El resultado es: %s\n", ft_strstr(str, to_find));
	return (0);
}
