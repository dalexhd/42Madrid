/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:46 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/10 20:29:55 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	t_uchar	*d;
	t_uchar	*s;

	d = (t_uchar*)dst;
	s = (t_uchar*)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (t_uchar)c)
			return (d + i + 1);
		i++;
	}
	return (0);
}
