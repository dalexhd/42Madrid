/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:57:37 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/19 13:24:52 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
