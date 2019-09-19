/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:09:33 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/11 20:18:30 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while (src[i] != '\0' && i <= n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%i: %c\n", i, dest[i]);
	}
	return (dest);
}


int		main(void)
{
	char	*ptr;
	char	*text;
	int		max;

	text = "Hola mundo";
	ft_strncpy(ptr, text, 4);
	return (0);
}
