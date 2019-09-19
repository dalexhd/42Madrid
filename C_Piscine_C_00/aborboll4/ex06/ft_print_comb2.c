/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:15:41 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/08 19:51:11 by aborboll         ###   ########.fr       */
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
	int		c;
	int		d;

	c = 0;
	d = 1;
	while (c < 99)
	{
		while (d <= 99)
		{
			if (c != d && c < d)
			{
				par(c);
				write(1, " ", 1);
				par(d);
				if (c <= 99 && d <= 98)
					write(1, ", ", 2);
			}
			d++;
		}
		c++;
		d = 0;
		(c <= 98) && write(1, ", ", 2);
	}
}


int main(void)
{
	ft_print_comb2();
	return (0);
}
