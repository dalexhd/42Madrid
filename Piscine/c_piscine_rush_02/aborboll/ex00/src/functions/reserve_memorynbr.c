/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve_memorynbr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:45:55 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 12:51:09 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*reserve_memorynbr(char *next)
{
	char	*nbr;
	int		i;

	i = 0;
	while (next[i] <= '9' && next[i] >= '0')
		i++;
	nbr = malloc(sizeof(char) * (i + 50));
	i = -1;
	while (next[++i] <= '9' && next[i] >= '0')
		nbr[i] = next[i];
	nbr[i] = '\0';
	return (nbr);
}
