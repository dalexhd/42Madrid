/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:23:22 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/17 15:44:17 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str)
{
	int	i;
	int num;
	int	f;
	int	neg;

	i = 0;
	f = 0;
	num = 0;
	neg = 0;
	while (str[i] != '\0' &&
	!(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
	str[i] == '\v' || str[i] == '\r' || str[i] == '\f'))
	{
		if (str[i] == '-')
			neg++;
		else if (str[i] != '+')
		{
			if (f == 0 && (str[i] >= '0' && str[i] <= '9'))
				num = num * 10 + ((int)str[i] - '0');
			else
				f = 1;
		}
		i++;
	}
	return (neg % 2 == 0) ? num * -1 : num;
}

int	main(void)
{
	char str[] = "---+-+12 34ab567";
	printf("El numero es: %i\n", ft_atoi(str));
	printf("El numero es: %i\n", atoi(str));
	return (0);
}
