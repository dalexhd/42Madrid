/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:57:37 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/18 15:08:41 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb >= 2147483647)
		return (0);
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
	if (nb < 0)
		return (1);
	if (nb <= 1)
		return (0);
	while (i >= 2)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}
