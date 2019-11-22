/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 17:46:59 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/10 17:47:05 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		k;
	char	*tmp;

	i = 0;
	k = 0;
	while (str[i])
		i++;
	if (!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (i)
		tmp[k++] = str[i-- - 1];
	tmp[k] = '\0';
	return (tmp);
}
