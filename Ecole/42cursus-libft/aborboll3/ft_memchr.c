/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:49 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/10 20:29:20 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	t_uchar	*d;

	d = (t_uchar*)s;
	i = 0;
	while (i < n)
	{
		if (d[i] == (t_uchar)c)
			return (d + i);
		i++;
	}
	return (0);
}
