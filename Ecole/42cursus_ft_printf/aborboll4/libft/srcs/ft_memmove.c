/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:35:18 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/11 20:35:04 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	t_uchar	*d;
	t_uchar	*s;
	int		i;

	i = 0;
	if (dst == '\0' && src == '\0')
		return (0);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		d = (t_uchar*)dst + len;
		s = (t_uchar*)src + len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}
