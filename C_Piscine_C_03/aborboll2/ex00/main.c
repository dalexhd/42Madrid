/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:53:19 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/16 15:00:26 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (i);
}

int	main(void)
{
	char	s1[] = "abc";
	char	s2[] = "Aadb";

	printf("%i", ft_strcmp(s1, s2));
	printf("%i", strcmp(s1, s2));
	return (0);
}
