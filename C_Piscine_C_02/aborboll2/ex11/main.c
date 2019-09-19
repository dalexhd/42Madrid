/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 11:35:54 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/12 12:32:11 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	to_hex(char a)
{
	char *abc;

	abc = "0123456789abcdef";
	if (a > 16)
	{
		to_hex(a / 16);
		to_hex(a % 16);
	}
	else
	{
		ft_putchar(abc[(int)a]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] >= '~')
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			to_hex(str[i]);
		}
		else
		{
			ft_putchar(str[i]);
		}
		i++;
	}
}

int		main(void)
{
	char	src[] = "Coucou\ntu vas bien";

	ft_putstr_non_printable(src);
	return (0);
}
