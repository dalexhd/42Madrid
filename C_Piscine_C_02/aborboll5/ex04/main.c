/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:10:25 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/11 19:58:56 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	while (str[0] != '\0')
	{
		if (str[0] < 97 || str[0] > 122)
			return (0);
		str++;
	}
	printf("El return es: %i \n", 1);
	return (1);
}

int	main(void)
{
	char *test;

	test = "holamundo";
	ft_str_is_lowercase(test);
	return (0);
}
