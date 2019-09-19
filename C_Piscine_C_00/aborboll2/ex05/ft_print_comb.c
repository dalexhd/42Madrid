/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 11:30:55 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/07 14:41:01 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putcomma(void)
{
	write(1, ", ", 2);
}

void	ft_putchar(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (a < '7')
	{
		ft_putcomma();
	}
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;

	a = '0' - 1;
	while (a++ < '7')
	{
		b = a;
		while (b++ < '8')
		{
			c = b;
			while (c++ < '9')
			{
				ft_putchar(a, b, c);
			}
		}
	}
}
