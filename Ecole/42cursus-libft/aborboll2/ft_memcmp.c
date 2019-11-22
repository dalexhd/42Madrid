/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:51 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/10 19:55:34 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
