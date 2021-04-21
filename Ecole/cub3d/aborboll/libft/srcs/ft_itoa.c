/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:44 by aborboll          #+#    #+#             */
/*   Updated: 2020/08/28 17:08:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char			*ft_itoa(int nbr)
{
	size_t	i;
	char	*ret;
	int		sign;

	i = 0;
	if (!(ret = ft_strnew(ft_numlen(nbr))))
		return (0);
	if (nbr == 0)
	{
		free(ret);
		return (ft_strdup("0"));
	}
	sign = (nbr < 0) ? 1 : 0;
	while (nbr != 0)
	{
		ret[i++] = ft_abs(nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign)
		ret[i++] = '-';
	ret[i++] = '\0';
	return (ft_strrev(ret));
}
