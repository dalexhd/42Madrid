/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_llong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:44 by aborboll          #+#    #+#             */
/*   Updated: 2020/02/09 04:10:03 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_llong(t_llong n)
{
	size_t	i;
	char	*ret;
	int		sign;

	i = 0;
	if (!(ret = ft_strnew(ft_numlen(n))))
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	sign = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		ret[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (sign)
		ret[i++] = '-';
	ret[i] = '\0';
	return (ft_strrev(ret));
}
