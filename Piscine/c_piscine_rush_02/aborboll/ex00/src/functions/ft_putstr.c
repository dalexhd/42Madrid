/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 10:45:50 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 14:33:08 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putstr_with_space(char *str)
{
	int		i;
	char	space;

	space = ' ';
	i = 0;
	while (*str)
		write(1, str++, 1);
	write(1, &space, 1);
}
