/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:50:46 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/11 19:17:51 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i + 1];
			tab[i + 1] = tab[i];
			tab[i] = tmp;
			i = 0;
		}
		else
		{
			i++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		printf("%d < ", tab[i]);
	}

}

int main(void)
{
	int size;
	int tab[6] = {5, 4, 2, 1, 3, 100};

	size = 6;
	ft_rev_int_tab(tab, size);
	return (0);
}
