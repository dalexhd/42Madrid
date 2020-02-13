/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:05:18 by aborboll          #+#    #+#             */
/*   Updated: 2020/02/09 04:11:12 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** @author	aborboll
** @param	{long nb}	The number
** @desc	Get number length
** @returns	int
*/

#include "libft.h"

int		ft_numlen(t_ullong nb)
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
