/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:12:21 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/11 22:13:12 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	n;
	char	v;

	i = 0;
	while (str[i] != '\0')
	{
		n = str[i - 1];
		v = str[i];
		if ((i == 0 || n == ' ' || n == '-' || n == '+'))
		{
			if (v >= 'a' && v <= 'z')
			{
				str[i] -= 32;
			}
		}
		i++;
	}
	for (int i = 0; i < 20; i++)
	{
		printf("%c", str[i]);
	}
	return (str);
}

int		main(void)
{
	char	*test;

	test = "Asd +a";
	ft_strcapitalize(test);
	return (0);
}
