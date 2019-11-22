/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:45:50 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/25 12:10:12 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/generic.h"

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

void	ft_putstr_with_space(char *str)
{
	int		i;

	i = 0;
	while (*str)
		ft_putchar(*str++);
	ft_putchar(' ');
}
