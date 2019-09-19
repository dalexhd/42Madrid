/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:58:54 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/19 15:53:49 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i < nb)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (i);
}

int	ft_is_prime(int nb)
{
	int	i;

	i = ft_sqrt(nb);
	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	while (i > 2)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = nb;
	while (i < 2147483647)
	{
		if (ft_is_prime(i + 1) == 1)
			return (i + 1);
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("%i\n", ft_find_next_prime(2147483640));
	return (0);
}
