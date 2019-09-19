/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:57:13 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/19 16:36:02 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int rt;
	int ort;

	if (nb < 1)
		return (0);
	rt = 1;
	ort = 0;
	while (ort != rt)
	{
		ort = rt;
		rt = ((nb / rt) + rt) / 2;
	}
	if (rt * rt != nb)
		return (0);
	return (rt);
}

int	main(void)
{
	printf("%i\n", ft_sqrt(1640045925));
	return (0);
}
