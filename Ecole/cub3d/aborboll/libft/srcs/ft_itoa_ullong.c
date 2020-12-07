/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ullong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:44 by aborboll          #+#    #+#             */
/*   Updated: 2020/08/28 17:08:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_itoa_ullong(t_ullong n)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!(ret = ft_strnew(ft_numlen(n))))
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	while (n != 0)
	{
		ret[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	ret[i] = '\0';
	return (ft_strrev(ret));
}
