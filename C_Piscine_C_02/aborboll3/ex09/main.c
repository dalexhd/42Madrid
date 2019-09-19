/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:12:21 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/12 15:37:18 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	bef;
	char	curr;

	i = 0;
	while (str[i] != '\0')
	{
		bef = str[i - 1];
		curr = str[i];
		if (i == 0 || bef == ' ' || bef == '-' || bef == '+')
		{
			if (curr >= 97 && curr <= 122)
				str[i] -= 32;
		}
		else if (curr >= 65 && curr <= 90)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

int		main(void)
{
	char	str[] = "2salut, comment tu vas ? 42Mots quarante-deux; cinquante+et+un";
	printf("%s\n", ft_strcapitalize(str));
	return (0);
}
