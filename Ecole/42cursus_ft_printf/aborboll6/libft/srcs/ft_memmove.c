/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:35:18 by aborboll          #+#    #+#             */
/*   Updated: 2020/02/09 06:16:58 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @param	{void *dst}		Memory area dst
** @param	{void *src}		Memory ares arc
** @param	{size_t len}	The number of bytes
** @desc					Copies len bytes from the memory of src to dst.
**							Memories may overlap. First, the bytes in src
**							are copied into a temporary array and then to dst.
** @returns					A pointer to the memory area dst
*/

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
