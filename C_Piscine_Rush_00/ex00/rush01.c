/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 17:09:38 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/08 19:49:05 by mrosario         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	print_top(int x, int y)
{
	int		en;

	en = x - 2;
	if (x > 0 && y > 0)
	{
		ft_putchar('/');
		while (en > 0)
		{
			ft_putchar('*');
			en--;
		}
		if (en == 0)
			ft_putchar('\\');
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
		ft_putchar('*');
		while (en > 0)
		{
			ft_putchar(' ');
			en--;
		}
		if (en == 0)
			ft_putchar('*');
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
		ft_putchar('\\');
		while (en > 0)
		{
			ft_putchar('*');
			en--;
		}
		if (en == 0)
			ft_putchar('/');
	}
}

void	rush(int x, int y)
{
	print_top(x, y);
	print_mid(x, y);
	print_last(x, y);
}
