/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:12:21 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/12 10:55:27 by aborboll         ###   ########.fr       */
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
			if (v >= 97 || v <= 122)
			{
				str[i] -= 32;
			}
		}
		i++;
	}
	return (str);
}

int		main(void)
{
	char	str[] = "rekt17+lol mdr mdr 4242l42";
	printf("%s\n", ft_strcapitalize(str));
	return (0);
}
