/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ullong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:44 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/09 18:21:24 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_ullong(t_ullong n)
{
	size_t	i;
	char	*ret;
	int		sign;

	i = 0;
	if (!(ret = (char *)malloc((sizeof(char) * 24) + 1)))
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	sign = (n < 0) ? 1 : 0;
	while (n != 0)
	{
		ret[i++] = (sign) ? (-1 * (n % 10)) + '0' : (n % 10) + '0';
		n /= 10;
	}
	if (sign)
		ret[i++] = '-';
	ret[i] = '\0';
	return (ft_strrev(ret));
}
