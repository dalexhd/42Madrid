/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 18:12:00 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/15 16:51:22 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(unsigned long long int n,
		unsigned long long int base)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

static char	get_char(unsigned long long int n)
{
	char	vals[16];
	int		i;

	i = -1;
	while (++i < 10)
		vals[i] = (char)(i + '0');
	vals[10] = 'a';
	vals[11] = 'b';
	vals[12] = 'c';
	vals[13] = 'd';
	vals[14] = 'e';
	vals[15] = 'f';
	return (vals[n]);
}

static char	*is_zero(unsigned long long int n)
{
	char	*res;

	if (n != 0)
		return (NULL);
	if (!(res = ft_strdup("0")))
		return (0);
	return (res);
}

char		*ft_utoabase(t_ullong n, t_ullong b)
{
	char	*res;
	int		i;

	if ((res = is_zero(n)))
		return (res);
	i = count_digits(n, b);
	if (!(res = ft_strnew(i)))
		return (0);
	i--;
	while (n != 0)
	{
		res[i] = get_char(n % b);
		i--;
		n /= b;
	}
	return (res);
}
