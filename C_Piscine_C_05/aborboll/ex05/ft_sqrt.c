/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 18:57:05 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/19 13:25:52 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	double rt;
	double ort;

	if (nb < 1)
		return (0);
	rt = 1;
	ort = 0;
	while (ort != rt)
	{
		ort = rt;
		rt = (((double)nb / rt) + rt) / 2;
	}
	if (rt * rt != nb)
		return (0);
	return (rt);
}
