/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 23:16:48 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/26 13:55:22 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;

	i = -1;
	*range = (int *)malloc(sizeof(**range) * (max - min + 1));
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	while (++i < (max - min))
		range[0][i] = min + i;
	return (i);
}
