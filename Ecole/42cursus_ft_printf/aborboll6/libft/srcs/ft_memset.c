/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:59 by aborboll          #+#    #+#             */
/*   Updated: 2020/02/09 06:20:22 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @param	{void *b}		The string on which to operate
** @param	{int c}			Value c (converted to an unsigned char)
** @param	{size_t len}	The number of bytes
** @desc					Fill with "len" bytes of "c" the memory of "s"
** @returns					A pointer to the memory area s
*/

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*d;

	d = (char*)b;
	i = 0;
	while (i < len)
	{
		d[i] = (t_uchar)c;
		i++;
	}
	return (d);
}
