/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:58:00 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/19 16:24:04 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	double rt;
	double ort;

	rt = 1;
	ort = 0;
	while (ort != rt)
	{
		ort = rt;
		rt = (((double)nb / rt) + rt) / 2;
	}
	return (rt);
}

int	ft_is_prime(int nb)
{
	int	i;

	if (nb < 2 || nb > 2147483647)
		return (0);
	i = ft_sqrt(nb);
	while (i > 1)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}

int	main(void)
{
	printf("%i\n", ft_is_prime(3));
	return (0);
}