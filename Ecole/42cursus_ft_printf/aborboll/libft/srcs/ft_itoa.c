/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:44 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/10 17:11:02 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


char			*ft_itoa(int nbr)
{
	size_t	i;
	char	*ret;
	int		sign;

	i = 0;
	if (!(ret = (char *)malloc(sizeof(char) * 12)))
		return (0);
	if (nbr == 0){
		free(ret);
		return (ft_strdup("0"));
	}
	sign = (nbr < 0) ? 1 : 0;
	while (nbr != 0)
	{
		ret[i++] = (sign) ? (-1 * (nbr % 10)) + '0' : (nbr % 10) + '0';
		nbr /= 10;
	}
	if (sign)
		ret[i++] = '-';
	ret[i++] = '\0';
	return (ft_strrev(ret));
}
