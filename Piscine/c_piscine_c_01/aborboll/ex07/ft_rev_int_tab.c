/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:50:46 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/10 13:20:06 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int temp[size];
	int start;
	int end;
	int current;

	start = 0;
	end = size;
	while (start <= size)
	{
		temp[start] = tab[end];
		end--;
		start++;
	}
	tab = temp;
}
