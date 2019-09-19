/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:19:42 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/17 16:38:10 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	long int	number;

	number = nb;
	if (nb < 0)
	{
		number *= -1;
		ft_putchar('-');
	}
	if (number < 10)
	{
		ft_putchar(number + 48);
	}
	else
	{
		ft_putnbr(number / 10);
		ft_putchar((number % 10) + 48);
	}
}
