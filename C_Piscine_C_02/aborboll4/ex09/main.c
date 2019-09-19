/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:12:21 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/13 10:23:08 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_is_alfanumeric(char a)
{

	if (((a < 'a' && a > 'z') || (a < 'A' && a > 'Z')))
	{

		return (0);
	}
	else
	{
				printf("--%c\n", a);
		return (1);
	}
}

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
		if (i == 0 || ft_is_alfanumeric(curr) == 1)
		{

			if (curr >= 97 && curr <= 122)
			{

				str[i] -= 32;
			}
		}
		if (curr >= 65 && curr <= 90)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

int		main(void)
{
	char	str[] = "9q^oex{;9j`tql	_,y19hj8^g#8iw}fln*;uif";
	printf("%s\n", ft_strcapitalize(str));
	return (0);
}
