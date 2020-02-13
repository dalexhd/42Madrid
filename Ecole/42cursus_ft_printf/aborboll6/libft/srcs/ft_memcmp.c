/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:51 by aborboll          #+#    #+#             */
/*   Updated: 2020/02/09 06:19:38 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @param	{void *s1}		Memory area s1
** @param	{void *s2}		Memory area s2
** @param	{size_t n}		The number of bytes
** @desc					Compares byte string s1 against byte string s2
** @returns					< 0 if s1 is less than s2, > 0 if s1 is graeter
**							than s2, = 0 if s1 is equal to s2
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_ulong i;
	t_uchar *s;
	t_uchar *c;

	i = 0;
	s = (t_uchar*)s1;
	c = (t_uchar*)s2;
	if (n == 0)
		return (0);
	while ((s[i] == c[i]) && i < n - 1)
		i++;
	return (s[i] - c[i]);
}
