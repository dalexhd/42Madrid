/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:41:38 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/10 16:26:19 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int current;
	int i;
	int temp;

	current = 0;
	while (current <= size - 1)
	{
		i = 0;
		while (i <= size - 2)
		{
			if (tab[i] > tab[current])
			{
				temp = tab[current];
				tab[current] = tab[i];
				tab[i] = temp;
			}
			i++;
		}
		current++;
	}
}
