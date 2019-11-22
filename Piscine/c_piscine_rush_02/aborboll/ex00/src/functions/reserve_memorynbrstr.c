/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reserve_memorynbrstr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:51:11 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 14:07:55 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*reserve_memorynbrstr(char *next, char *nbrstr)
{
	int		i;
	int		j;

	i = 0;
	while (next[i] != ':')
		i++;
	while (next[i] != ' ')
		i++;
	j = 0;
	while (next[++i] <= 126 && next[i] >= 33 && next[i])
		j++;
	nbrstr = malloc(sizeof(char) * j);
	i -= j;
	j = 0;
	while (next[i] <= 126 && next[i] >= 33)
	{
		nbrstr[j++] = next[i++];
	}
	return (nbrstr);
}
