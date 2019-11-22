/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmemcat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 14:07:58 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/25 14:09:53 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/generic.h"

char	*ft_strmemcat(char *full_buff, char *buff)
{
	int		c;
	int		i;
	char	*tmp;

	c = 0;
	i = 0;
	while (full_buff[c])
		c++;
	while (buff[i])
		i++;
	if (!(tmp = (char*)malloc(sizeof(char) * (i + c + 1))))
		return (NULL);
	c = 0;
	while (full_buff[c])
	{
		tmp[c] = full_buff[c];
		c++;
	}
	i = 0;
	while (buff[i])
		tmp[c++] = buff[i++];
	tmp[c] = '\0';
	return (tmp);
}
