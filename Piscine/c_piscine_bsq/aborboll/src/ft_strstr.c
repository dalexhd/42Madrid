/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:03:14 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 21:22:27 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/generic.h"

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (*str == *to_find && compare(str, to_find))
			return (str);
		str++;
	}
	return (0);
}
