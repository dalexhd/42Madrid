/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:35:18 by aborboll          #+#    #+#             */
/*   Updated: 2020/08/28 17:08:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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

	d = (t_uchar*)dst;
	s = (t_uchar*)src;
	if (*d == '\0' && *s == '\0')
		return (0);
	if (dst < src)
		ft_memcpy(dst, src, len);
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}
