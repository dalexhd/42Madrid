/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:05:18 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/10 20:27:44 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @author	aborboll
** @param	{long nb}	The number
** @desc	Get number length
** @returns	int
*/

int		ft_numlen(long nb)
{
	int		i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}
