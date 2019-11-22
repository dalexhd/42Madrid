/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:15:41 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/07 18:34:08 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	par(int i)
{
	int u;
	int d;

	u = i % 10;
	d = i / 10;
	u = u + 48;
	d = d + 48;
	write(1, &d, 1);
	write(1, &u, 1);
}

void	ft_print_comb2(void)
{
	char	comma;
	int		c;
	int		d;
	int		b;

	comma = ',';
	b = ' ';
	c = 0;
	d = 0;
	while (c < 99)
	{
		while (d <= 99)
		{
			par(c);
			write(1, &b, 1);
			par(d);
			(c <= 99 && d <= 98) && (write(1, &comma, 1) && write(1, &b, 1));
			d++;
		}
		c++;
		d = 0;
		(c <= 98) && write(1, &comma, 1);
	}
}
