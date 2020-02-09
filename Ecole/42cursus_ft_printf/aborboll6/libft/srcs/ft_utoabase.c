/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:12:00 by aborboll          #+#    #+#             */
/*   Updated: 2020/02/06 16:04:19 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sizechar(t_ullong i, int base)
{
	int		size;

	size = 0;
	if (i == 0)
		return (1);
	else
	{
		while (i != 0)
		{
			i = i / base;
			size++;
		}
	}
	return (size);
}

char	*ft_utoabase(t_ullong n, int base)
{
	int		i;
	char	*nbr;

	i = ft_sizechar(n, base);
	if (!(nbr = ft_strnew(i)))
		return (NULL);
	nbr[i + 1] = '\0';
	while (i-- > 0)
	{
		nbr[i] = (n % base) + ((n % base > 9) ? 'a' - 10 : '0');
		n = (n / base);
	}
	return (nbr);
}
