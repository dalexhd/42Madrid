/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 12:45:34 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/13 12:50:43 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_llong	ft_atoll(const char *str)
{
	long long int			i;
	int						sign;
	unsigned long long		res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = 0;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	if (res > 9223372036854775807LL)
		return (sign == 0 ? 0 : -1);
	return (sign == 1 ? res : -res);
}
