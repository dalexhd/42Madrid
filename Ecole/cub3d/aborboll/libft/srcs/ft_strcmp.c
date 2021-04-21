/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:42:52 by aborboll          #+#    #+#             */
/*   Updated: 2020/08/28 17:08:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	t_ulong i;
	t_uchar *d;
	t_uchar *e;

	d = (t_uchar*)s1;
	e = (t_uchar*)s2;
	i = 0;
	while ((d[i] == e[i]) && d[i] != '\0' && e[i] != '\0')
		i++;
	return (d[i] - e[i]);
}
