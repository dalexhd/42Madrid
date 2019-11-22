/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:19:42 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/17 12:32:33 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	int	number;

	if (nb < 0 && nb * -1)
	{
		ft_putchar('-');
	}
	number = nb;
	if (number < 10)
		ft_putchar(number + 48);
	else
	{
		ft_putnbr(number / 10);
		ft_putchar((number % 10) + 48);
	}
}
