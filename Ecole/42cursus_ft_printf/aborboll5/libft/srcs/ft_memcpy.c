/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:35:18 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/07 15:51:17 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	t_uchar	*s;
	t_uchar	*d;

	d = (t_uchar *)dst;
	s = (t_uchar *)src;
	i = 0;
	if (dst == '\0' && src == '\0')
		return (0);
	if (!n || dst == src)
		return (dst);
	while (n--)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
