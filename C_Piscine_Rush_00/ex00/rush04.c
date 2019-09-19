/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:09:38 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/08 19:36:12 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	print_top(int x, int y)
{
	int		en;

	en = x - 2;
	if (x > 0 && y > 0)
	{
		ft_putchar('A');
		while (en > 0)
		{
			ft_putchar('B');
			en--;
		}
		if (en == 0)
			ft_putchar('C');
		ft_putchar('\n');
	}
}

void	print_mid(int x, int y)
{
	int		fn;
	int		en;

	en = x - 2;
	fn = y - 2;
	while ((x > 0 && y > 0) && fn > 0)
	{
		ft_putchar('B');
		while (en > 0)
		{
			ft_putchar(' ');
			en--;
		}
		if (en == 0)
			ft_putchar('B');
		ft_putchar('\n');
		fn--;
		en = x - 2;
	}
}

void	print_last(int x, int y)
{
	int		fn;
	int		en;

	en = x - 2;
	fn = y - 2;
	if ((x > 0 && y > 0) && fn > -1)
	{
		ft_putchar('C');
		while (en > 0)
		{
			ft_putchar('B');
			en--;
		}
		if (en == 0)
			ft_putchar('A');
	}
}

void	rush(int x, int y)
{
	print_top(x, y);
	print_mid(x, y);
	print_last(x, y);
}
