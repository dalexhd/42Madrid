/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:10:13 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/11 19:58:14 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
{
	while (str[0] != '\0')
	{
		if (str[0] < 48 || str[0] > 57)
			return (0);
		str++;
	}
	printf("El return es: %i \n", 1);
	return (1);
}

int	main(void)
{
	char *test;

	test = "1234567a";
	ft_str_is_numeric(test);
	return (0);
}
