/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:24:12 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/17 16:36:41 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_display(int nbr, char *base, unsigned int length)
{
	unsigned int num;

	if (nbr < 0)
	{
		num = nbr * -1;
		ft_putchar('-');
	}
	else
		num = nbr;
	if (num >= length)
		ft_display(num / length, base, length);
	ft_putchar(base[num % length]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	length;

	length = 0;
	while (base[length] != '\0')
		length++;
	ft_display(nbr, base, length);
}

int		main(void)
{
	ft_putnbr_base(-4, "hola");
	return (0);
}
