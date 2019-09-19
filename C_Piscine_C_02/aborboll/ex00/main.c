/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:09:19 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/11 19:24:33 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	printf("La primera letra de la cadena es: %p\n", src);
	return (src);
}

int		main(void)
{
	char	*ptr;
	char	*text;
	int		max;
	char	*hola;

	text = "Hola mundo";
	hola = ft_strcpy(ptr, text);
	printf("La primera letra de la cadena es: %p\n", hola);
	return (0);
}
