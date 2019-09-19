/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:55:04 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/16 18:38:58 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n - 1)
		i++;
	return (s1[i] - s2[i]);
}

int	main(void)
{
	char			s1[] = "HOLA";
	char			s2[] = "HOLA";
	unsigned int	n = 4;

	printf("%i\n", ft_strncmp(s1, s2, n));
	printf("%i\n", strncmp(s1, s2, n));
	return (0);
}
