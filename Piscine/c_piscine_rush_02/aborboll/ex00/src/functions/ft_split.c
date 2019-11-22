/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarvaja <acarvaja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:04:26 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 22:28:27 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../lib/generic.h"

char	**ft_split(char *str, char *chars, int i, int j)
{
	char	**table;
	int		mem_range;

	table = malloc((calc_range(str, chars) + 1) * sizeof(char*));
	if (table == NULL)
		return (table);
	while (chars[j] != '\0')
		j++;
	while (ft_strstr_tunned(str, chars) != 0)
	{
		table[i++] = ft_strncpy(malloc(200), str, ft_strstr_tunned(str, chars));
		str = ft_strstr(str, chars);
		mem_range = j;
		while (mem_range-- > 0)
			str++;
	}
	if (i == 0)
	{
		table[i] = malloc(sizeof(char) * 200);
		table[i++] = str;
	}
	else
		table[i++] = str;
	return (table);
}
