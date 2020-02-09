/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:26 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/24 18:59:39 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	t_uchar	*tab;
	size_t	i;

	i = 0;
	if (!(tab = (t_uchar *)malloc(size * count)))
		return (NULL);
	while (i < count * size)
		tab[i++] = '\0';
	return (tab);
}
