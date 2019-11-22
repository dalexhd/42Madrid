/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_range.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:03:58 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 21:07:52 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/generic.h"

int		calc_range(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = 1;
	j = 0;
	ptr = str;
	while (charset[j] != '\0')
		j++;
	while (ft_strstr_tunned(ptr, charset) != 0)
	{
		ptr = ft_strstr(ptr, charset);
		k = j;
		while (k-- > 0)
			ptr++;
		i++;
	}
	return (i);
}
